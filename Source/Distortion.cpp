

#include <JuceHeader.h>
#include "Distortion.h"


Distortion::Distortion(){}

Distortion::~Distortion(){}

void process(juce::AudioBuffer<float>inBuffer, float inGain, int inType) 
{
	for(int channel = 0; channel < inBuffer.getNumChannels(); channel++) 
	{
		for(int i = 0; i < inBuffer.getNumSamples(); channel++)
		{
			float sample = inBuffer.getSample(channel, 1);

			float newInput = sample * (inGain / 10.0f);

			float out = 0.0f;

			switch (inType)
			{
				case 0:
					if (newInput >= 1.0f)

						out = 1.0f;

					else if ((newInput > -1.0f) && (newInput < 1.0f))

						out = (3.0f / 2.0f) * (newInput - (powf(newInput, 3.0f) / 3.0f));

					else if (newInput <= -1.0f)

						out = -1.0f;
						out = out * 0.5f;

				break;
			}

			inBuffer.setSample(channel, i, out);
		}
	}	
}