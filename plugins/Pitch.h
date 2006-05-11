/* -*- c-basic-offset: 4 indent-tabs-mode: nil -*-  vi:set ts=8 sts=4 sw=4: */

/*
    Vamp feature extraction plugins using Paul Brossier's Aubio library.

    Centre for Digital Music, Queen Mary, University of London.
    This file copyright 2006 Chris Cannam.
    
    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation; either version 2 of the
    License, or (at your option) any later version.  See the file
    COPYING included with this distribution for more information.

*/

#ifndef _PITCH_PLUGIN_H_
#define _PITCH_PLUGIN_H_

#include <vamp-sdk/Plugin.h>
#include <aubio/aubio.h>

class Pitch : public Vamp::Plugin
{
public:
    Pitch(float inputSampleRate);
    virtual ~Pitch();

    bool initialise(size_t channels, size_t stepSize, size_t blockSize);
    void reset();

    InputDomain getInputDomain() const { return TimeDomain; }

    std::string getName() const;
    std::string getDescription() const;
    std::string getMaker() const;
    int getPluginVersion() const;
    std::string getCopyright() const;

    ParameterList getParameterDescriptors() const;
    float getParameter(std::string) const;
    void setParameter(std::string, float);

    size_t getPreferredStepSize() const;
    size_t getPreferredBlockSize() const;

    OutputList getOutputDescriptors() const;

    FeatureSet process(float **inputBuffers, Vamp::RealTime timestamp);

    FeatureSet getRemainingFeatures();

protected:
    fvec_t *m_ibuf;
    aubio_pitchdetection_t *m_pitchdet;
    aubio_pitchdetection_type m_pitchtype;
    aubio_pitchdetection_mode m_pitchmode;
    size_t m_stepSize;
    size_t m_blockSize;
    size_t m_channelCount;
};


#endif
