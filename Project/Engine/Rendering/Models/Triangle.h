#pragma once
#include "Model.h"
namespace Engine {
	namespace Rendering
	{
		namespace Models
		{
			class Triangle : public Model
			{
			public:
				Triangle();
				~Triangle();

				void Create();
				virtual void update() override final;
				virtual void draw() override final;
			};
		}
	}
}