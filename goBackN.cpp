// GO BACK N

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    int windowSize, totalFrames, nextFrameToSend = 0, nextAckExpected = 0;
    bool frameLost;

    cout << "Enter the window size: ";
    cin >> windowSize;

    cout << "Enter the total number of frames to send: ";
    cin >> totalFrames;

    vector<bool> ackReceived(totalFrames, false);

    srand(time(0)); // Seed for random number generation

    while (nextAckExpected < totalFrames) {
        // Send frames within the window
        while (nextFrameToSend < nextAckExpected + windowSize && nextFrameToSend < totalFrames) {
            cout << "Sending frame " << nextFrameToSend << endl;
            nextFrameToSend++;
        }

        // Simulate frame loss
        frameLost = (rand() % 2 == 0); 

        if (frameLost) {
            cout << "Frame " << nextAckExpected << " lost!" << endl;
        } else {
            cout << "ACK received for frame " << nextAckExpected << endl;
            ackReceived[nextAckExpected] = true;
            nextAckExpected++;
        }

        // Go back N if frame lost
        if (!frameLost && nextAckExpected < totalFrames && !ackReceived[nextAckExpected]) {
            cout << "Timeout, retransmitting from frame " << nextAckExpected << endl;
            nextFrameToSend = nextAckExpected;
        }
    }

    cout << "All frames successfully sent!" << endl;
    return 0;
}