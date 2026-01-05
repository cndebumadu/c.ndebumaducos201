#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int load_data(const char filename[], int ids[], int scores[], int max_size) {
    ifstream fin(filename);
    if (!fin.is_open()) return 0;

    string line;
    getline(fin, line);

    int count = 0;
    while (getline(fin, line) && count < max_size) {
        if (line.size() == 0) continue;

        stringstream ss(line);
        string id_str, score_str;

        if (!getline(ss, id_str, ',')) continue;
        if (!getline(ss, score_str)) continue;

        int id = stoi(id_str);
        int score = stoi(score_str);

        ids[count] = id;
        scores[count] = score;
        count++;
    }

    fin.close();
    return count;
}

void print_all(int ids[], int scores[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "student_id: " << ids[i]
             << "   score: " << scores[i] << endl;
    }
}

void compute_stats(int scores[], int size, double &average, int &min_score, int &max_score) {
    if (size <= 0) {
        average = 0.0;
        min_score = 0;
        max_score = 0;
        return;
    }

    int sum = 0;
    min_score = scores[0];
    max_score = scores[0];

    for (int i = 0; i < size; ++i) {
        int s = scores[i];
        sum += s;

        if (s < min_score) min_score = s;
        if (s > max_score) max_score = s;
    }

    average = static_cast<double>(sum) / size;
}

void compute_grade_distribution(int scores[], int size,int &count_a, int &count_b,int &count_c, int &count_d,int &count_f) {count_a = count_b = count_c = count_d = count_f = 0;

    for (int i = 0; i < size; ++i) {
        int s = scores[i];

        if (s >= 70 && s <= 100) ++count_a;
        else if (s >= 60 && s <= 69) ++count_b;
        else if (s >= 50 && s <= 59) ++count_c;
        else if (s >= 45 && s <= 49) ++count_d;
        else if (s >= 0 && s <= 44) ++count_f;
    }
}

int pick_random_passing_student(int ids[], int scores[], int size) {
    int pass_indices[100];
    int pass_count = 0;

    for (int i = 0; i < size; ++i) {
        if (scores[i] >= 50) {
            pass_indices[pass_count++] = i;
        }
    }

    if (pass_count == 0) return -1;

    int r = rand() % pass_count;
    return pass_indices[r];
}

void save_summary(const char filename[], double average, int min_score,int max_score, int count_a, int count_b, int count_c,int count_d, int count_f, int number_of_students) {

    ofstream fout(filename);
    fout << "metric,value" << endl;
    fout << "number_of_students," << number_of_students << endl;
    fout << "average_score," << fixed << setprecision(2) << average << endl;
    fout << "minimum_score," << min_score << endl;
    fout << "maximum_score," << max_score << endl;
    fout << "a_count," << count_a << endl;
    fout << "b_count," << count_b << endl;
    fout << "c_count," << count_c << endl;
    fout << "d_count," << count_d << endl;
    fout << "f_count," << count_f << endl;

    fout.close();
}

int main() {
    int ids[100];
    int scores[100];
    int max_size = 100;

    int size = load_data("scores.csv", ids, scores, max_size);

    cout << "total_number_of_students: " << size << endl;

    if (size == 0) {
        cout << "no data loaded. exiting." << endl;
        return 0;
    }

    print_all(ids, scores, size);

    double average;
    int min_score, max_score;

    compute_stats(scores, size, average, min_score, max_score);

    cout << fixed << setprecision(2);
    cout << "average_score: " << average << endl;
    cout << "minimum_score: " << min_score << endl;
    cout << "maximum_score: " << max_score << endl;

    int count_a, count_b, count_c, count_d, count_f;

    compute_grade_distribution(scores, size,count_a, count_b, count_c, count_d, count_f);

    cout << "A: " << count_a << endl;
    cout << "B: " << count_b << endl;
    cout << "C: " << count_c << endl;
    cout << "D: " << count_d << endl;
    cout << "F: " << count_f << endl;

    srand(static_cast<unsigned int>(time(0)));

    int selected_index = pick_random_passing_student(ids, scores, size);

    if (selected_index == -1) {
        cout << "no passing student found." << endl;
    } else {
        cout << "lucky_selected_passing_student: student_id "
             << ids[selected_index]
             << "  score " << scores[selected_index] << endl;
    }

    save_summary("summary.csv", average, min_score, max_score,count_a, count_b, count_c, count_d, count_f, size);

    cout << "summary saved to summary.csv" << endl;

    return 0;
}
