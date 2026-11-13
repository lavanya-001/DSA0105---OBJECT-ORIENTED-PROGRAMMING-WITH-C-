#include <iostream>
using namespace std;

class TelemetryAuditor;

// Forward declaration of friend function
class Engine;
void inspectDiagnostics(const Engine& e,
                        const TelemetryAuditor& a);

class Engine {
private:
    int temperature;
    int rpm;

public:
    Engine(int t, int r) : temperature(t), rpm(r) {}

    friend void inspectDiagnostics(
        const Engine& e, const TelemetryAuditor& a);
};

class TelemetryAuditor {
private:
    int alertThreshold;

public:
    TelemetryAuditor(int threshold)
        : alertThreshold(threshold) {}

    friend void inspectDiagnostics(
        const Engine& e, const TelemetryAuditor& a);
};

// Friend function definition
void inspectDiagnostics(const Engine& e,
                        const TelemetryAuditor& a) {
    if (e.temperature > a.alertThreshold) {
        cout << "Warning: Engine overheat!" << endl;
    } else {
        cout << "Engine operating nominally at "
             << e.rpm << " RPM." << endl;
    }
}

int main() {
    Engine v8(105, 3200);
    TelemetryAuditor audit(100);

    inspectDiagnostics(v8, audit);

    return 0;
}
