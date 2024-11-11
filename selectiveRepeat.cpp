// SELECTIVE REPEAT 

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    int windowSize, totalFrames;

    cout << "Enter window size: ";
    cin >> windowSize;

    cout << "Enter number of frames to transmit: ";
    cin >> totalFrames;

    vector<int> sentFrames(totalFrames, 0);
    vector<int> ackReceived(totalFrames, 0);
    int nextFrameToSend = 0, nextAckExpected = 0;

    srand(time(0)); // Seed for random number generation

    while (nextAckExpected < totalFrames) {
        // Send frames within the window
        while (nextFrameToSend < totalFrames && nextFrameToSend < nextAckExpected + windowSize) {
            if (sentFrames[nextFrameToSend] == 0) {
                cout << "Sending frame " << nextFrameToSend << endl;
                sentFrames[nextFrameToSend] = 1;
            }
            nextFrameToSend++;
        }

        // Simulate ACK reception
        for (int i = nextAckExpected; i < nextFrameToSend; i++) {
            if (sentFrames[i] == 1 && ackReceived[i] == 0) {
                // Simulate ACK loss
                if (rand() % 2 == 0) {
                    cout << "ACK received for frame " << i << endl;
                    ackReceived[i] = 1;
                } else {
                    cout << "ACK lost for frame " << i << endl;
                }
            }
        }

        // Move the window forward by advancing nextAckExpected
        while (nextAckExpected < totalFrames && ackReceived[nextAckExpected] == 1) {
            nextAckExpected++;
        }

        // Retransmit unacknowledged frames in the current window
        for (int i = nextAckExpected; i < nextFrameToSend; i++) {
            if (sentFrames[i] == 1 && ackReceived[i] == 0) {
                cout << "Retransmitting frame " << i << endl;
            }
        }
    }

    cout << "All frames transmitted successfully." << endl;
    return 0;
}