#pragma once
#include "Model.h"
namespace Engine {
	namespace Rendering
	{
		namespace Models
		{
			class Quad : public Models::Model
			{
			public:
				Quad();
				~Quad();

				void Create();
				virtual void draw() override final;
				virtual void update() override final;
			};
		}
	}
}