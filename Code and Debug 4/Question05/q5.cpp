#include <iostream>
using namespace std;

class RawSocket {
public:
    void openPort(int port) {
        cout << "Port " << port << " opened." << endl;
    }

    void closePort() {
        cout << "Port closed." << endl;
    }
};

class SecureChannel : private RawSocket {
public:
    using RawSocket::closePort;

    void establishEncryptedTunnel(int port) {
        openPort(port);
        cout << "Tunnel encrypted with TLS 1.3" << endl;
    }
};

int main() {
    SecureChannel channel;

    channel.establishEncryptedTunnel(443);
    channel.closePort();

    return 0;
}
