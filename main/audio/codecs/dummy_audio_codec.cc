#include "dummy_audio_codec.h"
#include <cstring>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

DummyAudioCodec::DummyAudioCodec(int input_sample_rate, int output_sample_rate) {
    duplex_ = true;
    input_reference_ = false;
    input_channels_ = 1;
    input_sample_rate_ = input_sample_rate;
    output_sample_rate_ = output_sample_rate;
}

DummyAudioCodec::~DummyAudioCodec() {
}

int DummyAudioCodec::Read(int16_t* dest, int samples) {
    // Simulate audio capture delay
    int duration_ms = samples * 1000 / input_sample_rate_;
    if (duration_ms > 0) {
        vTaskDelay(pdMS_TO_TICKS(duration_ms));
    }
    
    // Fill with silence
    memset(dest, 0, samples * sizeof(int16_t));
    return samples;
}

int DummyAudioCodec::Write(const int16_t* data, int samples) {
    // Simulate audio playback delay
    int duration_ms = samples * 1000 / output_sample_rate_;
    if (duration_ms > 0) {
        vTaskDelay(pdMS_TO_TICKS(duration_ms));
    }
    return samples;
}
