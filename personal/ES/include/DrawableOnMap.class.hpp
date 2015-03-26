#ifndef DRAWABLE_ON_MAP_HPP
#define DRAWABLE_ON_MAP_HPP

#include "Component.hpp"
#include "GraphicAsset.hpp"
#include "Vector3.hpp"

struct DrawableOnMap_Data : public Component_Data {
	GraphicAsset	*asset;
	Vector3			position;
	Vector3			rotation;
};

class DrawableOnMap : public Component<DrawableOnMap_Data> {
	public	:
		void	setPosition(unsigned int, Vector3);
		void	setRotation(unsigned int, Vector3);
		void	load(unsigned int);
		void	unload(unsigned int);
		void	draw(unsigned int);
};

#endif
