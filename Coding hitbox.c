#include <stdio.h>

// Definisikan Struct untuk Hitbox (Lingkaran)
typedef struct {
    float x; // Koordinat pusat X
    float y; // Koordinat pusat Y
    float r; // Jari-jari lingkaran (Radius)
} Hitbox;


/**
 * Fungsi untuk mendeteksi tabrakan antar dua hitbox.
 * Menggunakan pointer (*status_tabrakan) untuk mengembalikan hasil (Passing by Reference).
 */
void check(Hitbox h1, Hitbox h2, int *status_tabrakan) {
    float kuadrat_jarak;

    // 1. Hitung Kuadrat Jarak antar pusat (k^2)
    // k^2 = (x1 - x2)^2 + (y1 - y2)^2
    kuadrat_jarak = (h1.x - h2.x) * (h1.x - h2.x) + (h1.y - h2.y) * (h1.y - h2.y);

    // 2. Hitung Kuadrat Jumlah Jari-jari ((r1 + r2)^2)
    float kuadrat_jumlah_jari2 = (h1.r + h2.r) * (h1.r + h2.r);

    // 3. Percabangan untuk menentukan tabrakan
    // Jika kuadrat jarak > kuadrat jumlah jari-jari, maka TIDAK BERTABRAKAN
    if (kuadrat_jarak > kuadrat_jumlah_jari2) {
        *status_tabrakan = 0; // Tidak Bertabrakan
    } else {
        *status_tabrakan = 1; // Bertabrakan
    }
}


void go() {
    Hitbox h1, h2;

    // --- Input Data Hitbox ---
    printf("Masukkan data hitbox 1 (pusat x, pusat y, jari-jari r): ");
    // Menggunakan operator alamat (&) untuk menyimpan nilai input ke anggota struct
    scanf("%f %f %f", &h1.x, &h1.y, &h1.r);

    printf("Masukkan data hitbox 2 (pusat x, pusat y, jari-jari r): ");
    scanf("%f %f %f", &h2.x, &h2.y, &h2.r);

    // --- Pemanggilan Fungsi Cek Tabrakan ---
    int status_tabrakan;
    // Meneruskan alamat dari variabel 'status_tabrakan' menggunakan pointer (&)
    check(h1, h2, &status_tabrakan);

    // --- Output Hasil ---
    if (status_tabrakan == 1) {
        printf("HIT\n");
    } else {
        printf("DIDn't HIT\n");
    }
}

int main() {
    go();
    return 0;
}
