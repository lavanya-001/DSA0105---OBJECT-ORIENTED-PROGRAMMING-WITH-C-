#include <iostream>
using namespace std;

class NetworkPacket {
public:
    virtual ~NetworkPacket() {}

    virtual void serialize() = 0;
    virtual int getPacketSize() = 0;
};

class VideoPacket : public NetworkPacket {
private:
    int frameID;

public:
    VideoPacket(int id) : frameID(id) {}

    void serialize() override {
        cout << "Serializing H.264 Video Frame: "
             << frameID << endl;
    }

    int getPacketSize() override {
        return 1024;
    }
};

int main() {
    VideoPacket packet(1042);

    packet.serialize();

    cout << "Packet Size: "
         << packet.getPacketSize() << " bytes" << endl;

    return 0;
}
