/**
 * @mainpage  Metode Penilaian Universitas Muhammadiyah Yogyakarta
 * 
 * @section intro_sec Pendahuluan
 * Program ini bertujuan untuk Melakukan Penilaian Mahasiswa Universitas Muhammadiyah Yogyakarta
 * 
 * @section note_sec Struktur Program
 * Program ini terdiri dari 3 Struktur program:
 * - \b Matakuliah :Mengetahui tentang apa saja di dalam matakuliah
 * - \b Pemrograman :mengetahui tentang matakuliah tentang pemrograman
 * - \b Jaringan :Mengeetahui tentang matakuliah tentang Jaringan.
 * 
 * @section 
 * @file terminal.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */



#include <iostream>
using namespace std;

class MataKuliah {
private:
    float presensi, activity, exercise, tugasakhir;

public:
    MataKuliah() {
        presensi = 0.0;
        activity = 0.0;
        exercise = 0.0;
        tugasakhir = 0.0;
    }

    virtual string namaMK() { return ""; }
    virtual void inputNilai() {}
    virtual float hitungNilai() { return 0; }
    virtual void checkLulus() {}

    void setPresensi(float p) {
        this->presensi = p;
    }
    float getPresensi() {
        return presensi;
    }
    void setActivity(float a) {
        this->activity = a;
    }
    float getActivity() {
        return activity;
    }
    void setExercise(float e) {
        this->exercise = e;
    }
    float getExercise() {
        return exercise;
    }
    void setTugasakhir(float t) {
        this->tugasakhir = t;
    }
    float getTugasakhir() {
        return tugasakhir;
    }
};

class Pemrograman : public MataKuliah {
public:
    string namaMK() {
        return "Pemrograman";
    }

    void inputNilai() {
        cout << "Masukkan Nilai Presensi: ";
        float nilPresensi;
        cin >> nilPresensi;
        setPresensi(nilPresensi);

        cout << "Masukkan Nilai Activity: ";
        float nilActivity;
        cin >> nilActivity;
        setActivity(nilActivity);

        cout << "Masukkan nilai Exercise: ";
        float nilExercise;
        cin >> nilExercise;
        setExercise(nilExercise);

        cout << "Masukkan Nilai Tugas Akhir: ";
        float nilTugasakhir;
        cin >> nilTugasakhir;
        setTugasakhir(nilTugasakhir);
    }

    float hitungNilai() {
        return (getPresensi() * 0.1) + (getActivity() * 0.2) + (getExercise() * 0.3) + (getTugasakhir() * 0.4);
    }

    void checkLulus() {
        float nilaiAkhir = hitungNilai();
        cout << "Nilai Akhir: " << nilaiAkhir << endl;
        if (nilaiAkhir >= 75) {
            cout << "Selamat, Anda lulus mata kuliah Pemrograman dengan nilai akhir: " << nilaiAkhir << endl;
        } else {
            cout << "Maaf, Anda tidak lulus mata kuliah Pemrograman." << endl;
        }
    }
};

class Jaringan : public MataKuliah {
public:
    string namaMK() {
        return "Jaringan";
    }

    void inputNilai() {
        cout << "Masukkan Nilai Activity: ";
        float nilActivity;
        cin >> nilActivity;
        setActivity(nilActivity);

        cout << "Masukkan nilai Exercise: ";
        float nilExercise;
        cin >> nilExercise;
        setExercise(nilExercise);
    }

    float hitungNilai() {
        return  (getActivity() * 0.1) + (getExercise() * 0.2);
    }

    void checkLulus() {
        float nilaiAkhir = hitungNilai();
        cout << "Nilai Akhir: " << nilaiAkhir << endl;
        if (nilaiAkhir >= 75) {
            cout << "Selamat, Anda lulus mata kuliah Jaringan dengan nilai akhir: " << nilaiAkhir << endl;
        } else {
            cout << "Maaf, Anda tidak lulus mata kuliah Jaringan." << endl;
        }
    }
};

int main() {
    char pilih;
    MataKuliah* mataKuliah;
    Pemrograman pemrograman;
    Jaringan jaringan;

    cout << "Pilih mata kuliah :" << endl;
    cout << "1.Pemrograman  " << endl;
    cout << "2.Jaringan " << endl;
    cout << "3.Keluar " << endl;
    cout << "Masukkan Pilihan: ";
    cin >> pilih;

    switch (pilih) {
        case '1':
            mataKuliah = &pemrograman;
            cout << "Matakuliah " << mataKuliah->namaMK() << endl;
            mataKuliah->inputNilai();
            mataKuliah->checkLulus();
            break;
        case '2':
            mataKuliah = &jaringan;
            cout << "Matakuliah " << mataKuliah->namaMK() << endl;
            mataKuliah->inputNilai();
            mataKuliah->checkLulus();
            break;
        case '3':
            cout << "Keluar dari program." << endl;
            return 0;
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
    }
}
