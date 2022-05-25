
#pragma once
#include <JuceHeader.h>

class Distortion  : public juce::Component
{
public:
    Distortion();
    ~Distortion() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void process(juce::AudioBuffer<float>, float inGain, int inType);

private:
    
};
