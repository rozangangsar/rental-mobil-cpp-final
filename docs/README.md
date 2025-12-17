## Anggota Kelompok

**Rozan Gangsar Adibrata**
- NIM: 23/521626/TK/57547
**Hammam Priyandono**
- NIM: 23/521232/TK/57494
**Ammar Ali Yasir**
- NIM: 23/520644/TK/57406

# Aplikasi Rental Mobil Sederhana

Aplikasi rental mobil "Just Rent!" berbasis console yang dikembangkan menggunakan C++ dengan pendekatan Object Oriented Programming (OOP).

## Deskripsi Singkat

Aplikasi ini menyediakan sistem manajemen lengkap untuk bisnis rental mobil dengan fitur:
- Manajemen data kendaraan (Create, Read, Update, Delete)
- Manajemen data penyewa
- Transaksi penyewaan dan pengembalian kendaraan
- Perhitungan biaya sewa otomatis
- Pencarian dan filter berdasarkan tipe kendaraan
- Load dan save data ke file

## Fitur Utama

### 1. Manajemen Kendaraan
- **Tambah Mobil**: Daftarkan kendaraan baru dengan ID, model, tipe, dan tarif harian
- **Edit Mobil**: Ubah informasi kendaraan yang sudah ada
- **Hapus Mobil**: Hapus data kendaraan dari sistem
- **Lihat Semua Mobil**: Tampilkan daftar lengkap semua kendaraan
- **Lihat Mobil Tersedia**: Filter hanya kendaraan yang masih bisa disewa
- **Cari Berdasarkan Tipe**: Cari kendaraan dengan tipe tertentu (SUV, Sedan, MPV, Truck)

### 2. Manajemen Penyewa
- **Daftar Penyewa Baru**: Catat informasi penyewa baru
- **Edit Data Penyewa**: Ubah informasi penyewa
- **Hapus Data Penyewa**: Hapus data penyewa dari sistem
- **Lihat Semua Penyewa**: Tampilkan daftar semua penyewa

### 3. Transaksi Penyewaan
- **Sewa Mobil**: Catat penyewaan dengan validasi otomatis
- **Kembalikan Mobil**: Proses pengembalian kendaraan
- **Lihat Riwayat Penyewaan**: Tampilkan riwayat transaksi aktif
- **Perhitungan Biaya Otomatis**: Sistem menghitung total biaya berdasarkan durasi dan tarif

### 4. File Management
- **Load Data dari File**: Baca data kendaraan dari `data/input.txt` (auto-load saat startup; bisa ulang via menu admin)
- **Simpan Data ke File**: Simpan data kendaraan ke `data/input.txt` (agar jadi 1 file saja)

## Struktur Proyek

```
ProgdasUAS/
- include/   (header files)
- src/       (implementasi .cpp dan main)
- data/      (sample/input-output data)
- docs/      (dokumentasi)
- bin/       (output executable)
- Makefile
```

## Persyaratan Sistem

- **Compiler**: GNU C++ (g++) atau compiler C++ lainnya yang mendukung C++11
- **OS**: Linux, Windows (dengan MinGW), atau macOS
- **RAM**: Minimal 256 MB
- **Disk Space**: Minimal 5 MB

## Cara Instalasi dan Menjalankan

### Opsi 1: Menggunakan Makefile (Linux/macOS)
```bash
cd ProgdasUAS
make              # Kompilasi
./rental          # Jalankan aplikasi
make clean        # Hapus file object dan executable
```

### Opsi 2: Kompilasi Manual dengan g++
```bash
g++ -std=c++11 -Iinclude -o rental   src/main.cpp src/Car.cpp src/Renter.cpp src/RentalManager.cpp src/User.cpp src/AuthenticationManager.cpp
./rental          # Linux/macOS
rental.exe        # Windows
```


### Opsi 3: Menggunakan IDE (Code::Blocks, Dev-C++, Visual Studio)
1. Buat project baru C++
2. Tambahkan semua file .cpp dan .h ke project
3. Set compiler ke g++ dengan standard C++11
4. Build dan Run

## Cara Penggunaan

Aplikasi otomatis memuat data mobil dari `data/input.txt` saat start. Alur singkat:
- Login: pilih 1 untuk login, 2 untuk daftar akun user baru, 0 untuk keluar.
- Admin: kelola mobil/penyewa, transaksi, info, load/save data mobil.
- User: lihat/sewa mobil; ID penyewa otomatis = username login (jika belum ada data penyewa, diminta isi nama/telepon/alamat sekali).

Menu utama (ringkas):
```
JUST RENT! - APLIKASI RENTAL MOBIL
1. Login
2. Daftar Akun (User)
0. Keluar
```

### Contoh Penggunaan

**Menambah Mobil:**
1. Pilih menu 1 (Kelola Data Mobil)
2. Pilih sub-menu 1 (Tambah Mobil)
3. Masukkan data sesuai prompt

**Sewa Mobil (User):**
1. Login sebagai user
2. Pilih menu 3 (Sewa Mobil)
3. Masukkan ID mobil dan jumlah hari (akun login otomatis jadi ID penyewa; jika belum ada data penyewa, isi nama/telepon/alamat)
4. Sistem menghitung total biaya otomatis dan menandai mobil sebagai disewa

**Simpan Data Mobil:**
1. Menu admin ? Simpan Data ke File
2. Masukkan nama file (default: `data/output.txt`)
3. Data mobil disimpan dalam format `ID Model Tipe Tarif`
> Catatan: Data penyewa dan riwayat sewa saat ini tidak disimpan ke file; akan hilang saat aplikasi ditutup.


## Format File

### data/input.txt (Format: ID Model Tipe Tarif)
```
MBL001 Toyota_Avanza SUV 350000
MBL002 Honda_City Sedan 300000
MBL003 Daihatsu_Terios SUV 320000
...
```

## Fitur-Fitur Teknis

- **Vector Container**: Menggunakan `vector<Car>` dan `vector<Renter>` untuk dynamic array
- **Pointer**: Menggunakan pointer untuk return value pada fungsi pencarian
- **File Handling**: Menggunakan `ifstream` dan `ofstream` untuk baca/tulis file
- **Input Validation**: Validasi untuk mencegah duplikasi ID dan error input
- **Hierarchical Menu**: Sistem menu berlapis dengan loop untuk user experience



