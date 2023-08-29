#include <iostream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

void bruteForce(const string& password, int maxLength, string current = "")
{
    if (current.length() == maxLength)
    {
        if (current == password)
        {
            cout << "Password found: " << current << endl;
            return;
        }
        return;
    }

    for (char c = ' '; c <= '~'; c++) // Try all printable ASCII characters
    {
        bruteForce(password, maxLength, current + c);
    }
}

int main()
{
    string password;
    int maxLength;

    cout << "Enter the password to brute force: ";
    cin >> password;

    cout << "Enter the maximum length of the password: ";
    cin >> maxLength;

    cout << "Starting brute force..." << endl;

    auto start = chrono::high_resolution_clock::now();

    bruteForce(password, maxLength);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Brute force completed in " << duration.count() << " seconds." << endl;

    return 0;
}
