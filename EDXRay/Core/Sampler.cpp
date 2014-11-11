#include "Sampler.h"

#include "Memory/Memory.h"
#include "RNG/Random.h"

namespace EDX
{
	namespace RayTracer
	{
		SampleBuffer::~SampleBuffer()
		{
			SafeDeleteArray(p1D);
			SafeDeleteArray(p2D);
		}

		SampleBuffer* SampleBuffer::Duplicate(uint count) const
		{
			SampleBuffer* pRet = new SampleBuffer[count];

			for (auto i = 0; i < count; i++)
			{
				pRet[i].count1D = count1D;
				pRet[i].count2D = count2D;
				pRet[i].Validate();
			}

			return pRet;
		}

		void SampleBuffer::Validate()
		{
			SafeDeleteArray(p1D);
			SafeDeleteArray(p2D);

			if (count1D > 0)
				p1D = new float[count1D];
			if (count2D > 0)
				p2D = new Vector2[count2D];
		}


		Sample::Sample(RandomGen& random)
		{
			u = random.Float();
			v = random.Float();
			w = random.Float();
		}
	}
}