#include <iostream>

class AudioBuffer {
public:
    int *samples;
    int capacity;

    AudioBuffer(int cap) : capacity(cap) {
        samples = new int[capacity];

        for (int i = 0; i < capacity; i++) {
            samples[i] = i * 10;
        }

        std::cout << "Original buffer allocated: "
                  << static_cast<void*>(samples) << std::endl;
    }

    // Deep copy constructor
    AudioBuffer(const AudioBuffer &other)
        : capacity(other.capacity) {
        samples = new int[capacity];

        for (int i = 0; i < capacity; i++) {
            samples[i] = other.samples[i];
        }

        std::cout << "Copied buffer allocated: "
                  << static_cast<void*>(samples) << std::endl;
    }

    ~AudioBuffer() {
        std::cout << "Deallocating buffer: "
                  << static_cast<void*>(samples) << std::endl;
        delete[] samples;
    }
};

void processAudio(AudioBuffer buf) {
    std::cout << "Processing sample 0: "
              << buf.samples[0] << std::endl;
}

int main() {
    AudioBuffer track(5);

    processAudio(track);

    std::cout << "Back in main, sample 0: "
              << track.samples[0] << std::endl;

    return 0;
}
