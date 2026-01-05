#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int loadData(const char filename[], int ids[], int scores[], int maxSize) {
    ifstream fin(filename);
    if (!fin.is_open()) return 0;
    string line;
    getline(fin, line);
    int count = 0;
    while (getline(fin, line) && count < maxSize) {
        if (line.size() == 0) continue;
        stringstream ss(line);
        string idStr, scoreStr;
        if (!getline(ss, idStr, ',')) continue;
        if (!getline(ss, scoreStr)) continue;
        int id = stoi(idStr);
        int score = stoi(scoreStr);
        ids[count] = id;
        scores[count] = score;
        count++;
    }
    fin.close();
    return count;
}

void printAll(int ids[], int scores[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "StudentID: " << ids[i] << "   Score: " << scores[i] << endl;
    }
}

void computeStats(int scores[], int size, double &average, int &minScore, int &maxScore) {
    if (size <= 0) {
        average = 0.0;
        minScore = 0;
        maxScore = 0;
        return;
    }
    int sum = 0;
    minScore = scores[0];
    maxScore = scores[0];
    for (int i = 0; i < size; ++i) {
        int s = scores[i];
        sum += s;
        if (s < minScore) minScore = s;
        if (s > maxScore) maxScore = s;
    }
    average = static_cast<double>(sum) / size;
}

void computeGradeDistribution(int scores[], int size, int &countA, int &countB, int &countC, int &countD, int &countF) {
    countA = countB = countC = countD = countF = 0;
    for (int i = 0; i < size; ++i) {
        int s = scores[i];
        if (s >= 70 && s <= 100) ++countA;
        else if (s >= 60 && s <= 69) ++countB;
        else if (s >= 50 && s <= 59) ++countC;
        else if (s >= 45 && s <= 49) ++countD;
        else if (s >= 0 && s <= 44) ++countF;
    }
}

int pickRandomPassingStudent(int ids[], int scores[], int size) {
    int passIndices[100];
    int passCount = 0;
    for (int i = 0; i < size; ++i) {
        if (scores[i] >= 50) {
            passIndices[passCount++] = i;
        }
    }
    if (passCount == 0) return -1;
    int r = rand() % passCount;
    return passIndices[r];
}

void saveSummary(const char filename[], double average, int minScore, int maxScore, int countA, int countB, int countC, int countD, int countF, int numberOfStudents) {
    ofstream fout(filename);
    fout << "Metric,Value" << endl;
    fout << "Number of Students," << numberOfStudents << endl;
    fout << "Average Score," << fixed << setprecision(2) << average << endl;
    fout << "Minimum Score," << minScore << endl;
    fout << "Maximum Score," << maxScore << endl;
    fout << "A Count," << countA << endl;
    fout << "B Count," << countB << endl;
    fout << "C Count," << countC << endl;
    fout << "D Count," << countD << endl;
    fout << "F Count," << countF << endl;
    fout.close();
}

int main() {
    int ids[100];
    int scores[100];
    int maxSize = 100;
    int size = loadData("scores.csv", ids, scores, maxSize);
    cout << "Total number of students: " << size << endl;
    if (size == 0) {
        cout << "No data loaded. Exiting." << endl;
        return 0;
    }
    printAll(ids, scores, size);
    double average;
    int minScore, maxScore;
    computeStats(scores, size, average, minScore, maxScore);
    cout << fixed << setprecision(2);
    cout << "Average score: " << average << endl;
    cout << "Minimum score: " << minScore << endl;
    cout << "Maximum score: " << maxScore << endl;
    int countA, countB, countC, countD, countF;
    computeGradeDistribution(scores, size, countA, countB, countC, countD, countF);
    cout << "A: " << countA << endl;
    cout << "B: " << countB << endl;
    cout << "C: " << countC << endl;
    cout << "D: " << countD << endl;
    cout << "F: " << countF << endl;
    srand(static_cast<unsigned int>(time(0)));
    int selectedIndex = pickRandomPassingStudent(ids, scores, size);
    if (selectedIndex == -1) {
        cout << "No passing student to select." << endl;
    } else {
        cout << "Lucky selected passing student: StudentID " << ids[selectedIndex] << "  Score " << scores[selectedIndex] << endl;
    }
    saveSummary("summary.csv", average, minScore, maxScore, countA, countB, countC, countD, countF, size);
    cout << "Summary saved to summary.csv" << endl;
    return 0;
}
