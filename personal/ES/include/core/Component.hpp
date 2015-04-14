#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

#include <cassert>
#include <mutex>
#include <array>
#include <vector>
#include <map>
#include <algorithm>

#include "core/Entity.hpp"
#include "core/ComponentMask.hpp"

namespace NG {

#define STATE_NOT_FOUND -1

	class Entity;

	class AComponent {

		public :

			unsigned int							ID;
			static unsigned int				Count;

		protected :

			AComponent();
			virtual ~AComponent();
	};

	class ComponentData {

		public :

			int					State;

			ComponentData();
			virtual ~ComponentData();

	};

	extern std::vector<AComponent*> Components;
	extern std::vector<Entity*>			Entities;

	template<class T>
		class DataType {

			private :

				std::mutex	Mutex;
				T						Data;

			public :

				DataType() {}
				~DataType() {}

				void SetData(T data) {
					Mutex.lock();
					Data = data;
					Mutex.unlock();
				}

				T GetData(void) {
					T data;
					Mutex.lock();
					data = Data;
					Mutex.unlock();
					return data;
				}

				int GetState() {
					int state;
					Mutex.lock();
					state = Data.State;
					Mutex.unlock();
					return state;
				}

				void	SetState(int state) {
					Mutex.lock();
					Data.State = state;
					Mutex.unlock();
				}
		};

	template<class T>
		class Component : public AComponent {

			private :

				std::map<unsigned int,DataType<T>*>	Datas;

			public :

				Component()	
					: AComponent()
				{
					T t;
					ComponentData* d = dynamic_cast<ComponentData*>(&t);
					assert(d != NULL);
					d = NULL;

					Components.push_back(this);
				}

				~Component() { 
					Datas.clear();
					Components.erase(std::find(Components.begin(), Components.end(),this));
				}

				void	Register(unsigned int key) {
					typename std::map<unsigned int,DataType<T>*>::iterator it;
					it = Datas.find(key);
					if (it == Datas.end()) {
						Entities[key]->Mask[this->ID] = 1;
						Datas[key] = new DataType<T>();
					}
				}

				T	GetData(unsigned int key) {
					typename std::map<unsigned int,DataType<T>*>::iterator it;
					it = Datas.find(key);
					T t;
					if (it != Datas.end())
						t = it->second->GetData();
					else
						t.State = -1;
					return t;	
				}

				int	GetState(unsigned int key) {
					typename std::map<unsigned int,DataType<T>*>::iterator it;
					it = Datas.find(key);
					int state;
					if (it != Datas.end())
						state = it->second->GetState();
					else
						state = STATE_NOT_FOUND;
					return state;	
				}

				void	SetData(unsigned int key, T data) {
					typename std::map<unsigned int,DataType<T>*>::iterator it;
					it = Datas.find(key);
					if (it != Datas.end()) {
						it->second->SetData(data);
					}
				}

				unsigned int	Size(void) {
					return Datas.size();
				}
		};


	class TestComponentData : public ComponentData {
		public:
			int x,y,w,h;
			std::string title;
			TestComponentData() : 
				ComponentData(), 
				x(0), 
				y(0), 
				w(0), 
				h(0), 
				title() 
		{}
	};

#ifdef SWIG 
	%template(Component_TestComponent) Component<TestComponentData>; 
#endif
	class TestComponent : public Component<TestComponentData> {
		public:

#ifndef SWIG
			class Data : public TestComponentData {};
#endif
			TestComponent() : 
				Component() 
		{}
			~TestComponent() {}
	};

	class RetestComponentData : public ComponentData {
		public :
			float u,v;
			std::string textureName;
	};

#ifdef SWIG 
	%template(Component_RetestComponent) Component<RetestComponentData>; 
#endif
	class RetestComponent : public Component<RetestComponentData> {
		public:
			RetestComponent() : Component() {}
			~RetestComponent() {}
	};
}

#endif
