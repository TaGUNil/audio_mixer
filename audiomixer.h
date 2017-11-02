#pragma once

#include <cstddef>
#include <cstdint>

#ifndef AUDIOMIXER_BUFFER_SIZE
#define AUDIOMIXER_BUFFER_SIZE 4096
#endif

#include "audiotrack.h"

class AudioMixer
{
public:
    typedef AudioTrack::Mode Mode;

    typedef AudioTrack Track;

    typedef AudioTrack::Fade Fade;

    static const int TRACKS = 4;

    static const size_t AUDIOMIXER_BUFFER_LENGTH = AUDIOMIXER_BUFFER_SIZE / 4;

public:
    AudioMixer(WavReader::TellCallback tell_callback,
               WavReader::SeekCallback seek_callback,
               WavReader::ReadCallback read_callback,
               unsigned long sampling_rate,
               unsigned int channels);

    int start(void *file, Mode mode, uint16_t level, Fade fade_mode = Fade::None, uint16_t fade_length_ms = 0);

    void fade(int track, uint16_t level, Fade fade_mode = Fade::None, uint16_t fade_length_ms = 0);

    void stop(int track, Fade fade_mode = Fade::None, uint16_t fade_length_ms = 0);

    void clear();

    size_t play(int16_t *buffer, size_t frames);

    unsigned int channels()
    {
        return channels_;
    }

    unsigned long samplingRate()
    {
        return sampling_rate_;
    }

private:
    unsigned long sampling_rate_;
    unsigned int channels_;

    Track tracks_[TRACKS];

    int32_t sample_buffer_[AUDIOMIXER_BUFFER_LENGTH];
};
