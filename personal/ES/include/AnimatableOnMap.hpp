#ifndef ANIMATABLE_ON_MAP_HPP
#define ANIMATABLE_ON_MAP_HPP

#include "Component.hpp"
#include "GraphicAsset.hpp"

struct AnimatableOnMap_Data {
	GraphicAsset	*asset;
	int				currentFrame;
	int				nbFrames;
	int				duration;
};

class AnimatableOnMap : public Component<AnimatableOnMap_Data> {
	public :
		void	nextFrame(unsigned int);
		void	restart(unsigned int);
		void	setFrame(unsigned int, int);
		void	setDuration(unsigned int, int);
};

#endif
