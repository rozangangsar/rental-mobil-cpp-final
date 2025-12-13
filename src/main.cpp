#include "RentalManager.h"
#include "AuthenticationManager.h"
#include <iostream>
#include <string>
using namespace std;

void displayLoginScreen() {
    cout << "\n-========================================-" << endl;
    cout << "    JUST RENT! - APLIKASI RENTAL MOBIL     " << endl;
    cout << "-========================================-" << endl;
    cout << "\n===    SELAMAT DATANG DI JUST RENT!    ===" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilihan Anda: ";
}

void displayAdminMenu() {
    cout << "\n-========================================-" << endl;
    cout << "       DASHBOARD ADMIN JUST RENT!         "   << endl;
    cout << "-=========================================-" << endl;
    cout << "\n=== MENU UTAMA ADMIN ===" << endl;
    cout << "1. Kelola Data Mobil" << endl;
    cout << "2. Kelola Data Penyewa" << endl;
    cout << "3. Transaksi Penyewaan" << endl;
    cout << "4. Lihat Informasi" << endl;
    cout << "5. Muat Data dari File" << endl;
    cout << "6. Simpan Data ke File" << endl;
    cout << "0. Logout" << endl;
    cout << "Pilihan Anda: ";
}

void displayUserMenu() {
    cout << "\n-========================================-" << endl;
    cout << "     JUST RENT! PILIH MOBIL FAVORITMU!     " << endl;
    cout << "-=========================================-" << endl;
    cout << "\n=== MENU UTAMA USER ===" << endl;
    cout << "1. Lihat Daftar Mobil Tersedia" << endl;
    cout << "2. Cari Mobil Berdasarkan Tipe" << endl;
    cout << "3. Sewa Mobil" << endl;
    cout << "4. Lihat Riwayat Penyewaan Saya" << endl;
    cout << "0. Logout" << endl;
    cout << "Pilihan Anda: ";
}

void displayCarMenu() {
    cout << "\n=== KELOLA DATA MOBIL ===" << endl;
    cout << "1. Tambah Mobil" << endl;
    cout << "2. Edit Mobil" << endl;
    cout << "3. Hapus Mobil" << endl;
    cout << "4. Lihat Semua Mobil" << endl;
    cout << "5. Lihat Mobil Tersedia" << endl;
    cout << "6. Cari Mobil Berdasarkan Tipe" << endl;
    cout << "0. Kembali" << endl;
    cout << "Pilihan Anda: ";
}

void displayRenterMenu() {
    cout << "\n=== KELOLA DATA PENYEWA ===" << endl;
    cout << "1. Daftarkan Penyewa Baru" << endl;
    cout << "2. Edit Data Penyewa" << endl;
    cout << "3. Hapus Data Penyewa" << endl;
    cout << "4. Lihat Semua Penyewa" << endl;
    cout << "0. Kembali" << endl;
    cout << "Pilihan Anda: ";
}

void displayTransactionMenu() {
    cout << "\n=== TRANSAKSI PENYEWAAN ===" << endl;
    cout << "1. Sewa Mobil" << endl;
    cout << "2. Kembalikan Mobil" << endl;
    cout << "3. Lihat Riwayat Penyewaan" << endl;
    cout << "0. Kembali" << endl;
    cout << "Pilihan Anda: ";
}

void displayViewMenu() {
    cout << "\n=== LIHAT INFORMASI ===" << endl;
    cout << "1. Cek Ketersediaan Mobil" << endl;
    cout << "2. Lihat Semua Mobil" << endl;
    cout << "3. Lihat Semua Penyewa" << endl;
    cout << "0. Kembali" << endl;
    cout << "Pilihan Anda: ";
}

int main() {
    RentalManager manager;
    AuthenticationManager authManager;
    
    manager.loadFromFile("data/input.txt");

    int mainChoice, carChoice, renterChoice, transChoice, viewChoice, loginChoice;
    string username, password, carID, carModel, carType, renterID, renterName, phone, address, days, rate;

    while (true) {
        displayLoginScreen();
        cin >> loginChoice;
        cin.ignore();

        if (loginChoice == 0) {
            cout << "\nTerima kasih telah menggunakan aplikasi ini. Sampai jumpa!" << endl;
            return 0;
        }

        if (loginChoice == 2) {
            cout << "\n=== DAFTAR AKUN USER BARU ===" << endl;
            cout << "Masukkan username: ";
            getline(cin, username);
            cout << "Masukkan password: ";
            getline(cin, password);
            authManager.addUser(username, password, USER);
            continue;
        }

        if (loginChoice < 1 || loginChoice > 2) {
            cout << "Username/Password tidak valid!" << endl;
            continue;
        }

        cout << "\nMasukkan Username: ";
        getline(cin, username);
        cout << "Masukkan Password: ";
        getline(cin, password);

        User* loggedInUser = authManager.login(username, password);

        if (loggedInUser == NULL) {
            cout << "\nCoba lagi atau daftar akun baru (Pilihan 2)" << endl;
            continue;
        }

        // ===== ADMIN MENU =====
        if (loggedInUser->getRole() == ADMIN) {
            while (true) {
                displayAdminMenu();
                cin >> mainChoice;
                cin.ignore();

                if (mainChoice == 0) {
                    authManager.logout();
                    break;
                }

                switch (mainChoice) {
                    case 1: {
                        // Kelola Data Mobil (admin)
                        while (true) {
                            displayCarMenu();
                            cin >> carChoice;
                            cin.ignore();

                            switch (carChoice) {
                                case 1: {
                                    cout << "\n--- Tambah Mobil Baru ---" << endl;
                                    cout << "ID Mobil: ";
                                    getline(cin, carID);
                                    cout << "Model Mobil: ";
                                    getline(cin, carModel);
                                    cout << "Tipe Mobil (SUV/Sedan/MPV/Truck): ";
                                    getline(cin, carType);
                                    cout << "Tarif Harian (Rp): ";
                                    getline(cin, rate);
                                    manager.addCar(carID, carModel, carType, stol(rate));
                                    break;
                                }
                                case 2: {
                                    cout << "\n--- Edit Data Mobil ---" << endl;
                                    cout << "ID Mobil yang akan diedit: ";
                                    getline(cin, carID);
                                    cout << "Model Mobil Baru: ";
                                    getline(cin, carModel);
                                    cout << "Tipe Mobil Baru: ";
                                    getline(cin, carType);
                                    cout << "Tarif Harian Baru (Rp): ";
                                    getline(cin, rate);
                                    manager.editCar(carID, carModel, carType, stol(rate));
                                    break;
                                }
                                case 3: {
                                    cout << "\n--- Hapus Mobil ---" << endl;
                                    cout << "ID Mobil yang akan dihapus: ";
                                    getline(cin, carID);
                                    manager.deleteCar(carID);
                                    break;
                                }
                                case 4: {
                                    manager.viewAllCars();
                                    break;
                                }
                                case 5: {
                                    manager.viewAvailableCars();
                                    break;
                                }
                                case 6: {
                                    cout << "\nMasukkan tipe mobil (SUV/Sedan/MPV/Truck): ";
                                    getline(cin, carType);
                                    manager.searchCarByType(carType);
                                    break;
                                }
                                case 0:
                                    break;
                                default:
                                    cout << "Pilihan tidak valid!" << endl;
                            }
                            if (carChoice == 0) break;
                        }
                        break;
                    }

                    case 2: {
                        // Kelola Data Penyewa
                        while (true) {
                            displayRenterMenu();
                            cin >> renterChoice;
                            cin.ignore();

                            switch (renterChoice) {
                                case 1: {
                                    cout << "\n--- Daftarkan Penyewa Baru ---" << endl;
                                    cout << "ID Penyewa: ";
                                    getline(cin, renterID);
                                    cout << "Nama Penyewa: ";
                                    getline(cin, renterName);
                                    cout << "Nomor Telepon: ";
                                    getline(cin, phone);
                                    cout << "Alamat: ";
                                    getline(cin, address);
                                    manager.addRenter(renterID, renterName, phone, address);
                                    break;
                                }
                                case 2: {
                                    cout << "\n--- Edit Data Penyewa ---" << endl;
                                    cout << "ID Penyewa yang akan diedit: ";
                                    getline(cin, renterID);
                                    cout << "Nama Baru: ";
                                    getline(cin, renterName);
                                    cout << "Nomor Telepon Baru: ";
                                    getline(cin, phone);
                                    cout << "Alamat Baru: ";
                                    getline(cin, address);
                                    manager.editRenter(renterID, renterName, phone, address);
                                    break;
                                }
                                case 3: {
                                    cout << "\n--- Hapus Data Penyewa ---" << endl;
                                    cout << "ID Penyewa yang akan dihapus: ";
                                    getline(cin, renterID);
                                    manager.deleteRenter(renterID);
                                    break;
                                }
                                case 4: {
                                    manager.viewAllRenters();
                                    break;
                                }
                                case 0:
                                    break;
                                default:
                                    cout << "Pilihan tidak valid!" << endl;
                            }
                            if (renterChoice == 0) break;
                        }
                        break;
                    }

                    case 3: {
                        // Transaksi Penyewaan
                        while (true) {
                            displayTransactionMenu();
                            cin >> transChoice;
                            cin.ignore();

                            switch (transChoice) {
                                case 1: {
                                    cout << "\n--- Sewa Mobil ---" << endl;
                                    cout << "ID Penyewa: ";
                                    getline(cin, renterID);
                                    cout << "ID Mobil yang disewa: ";
                                    getline(cin, carID);
                                    cout << "Jumlah Hari: ";
                                    getline(cin, days);

                                    Car* car = manager.findCar(carID);
                                    if (car != NULL) {
                                        manager.rentCar(renterID, carID, stoi(days), car->getDailyRate());
                                    }
                                    break;
                                }
                                case 2: {
                                    cout << "\n--- Kembalikan Mobil ---" << endl;
                                    cout << "ID Mobil yang dikembalikan: ";
                                    getline(cin, carID);
                                    manager.returnCar(carID);
                                    break;
                                }
                                case 3: {
                                    manager.viewRentalHistory();
                                    break;
                                }
                                case 0:
                                    break;
                                default:
                                    cout << "Pilihan tidak valid!" << endl;
                            }
                            if (transChoice == 0) break;
                        }
                        break;
                    }

                    case 4: {
                        // Lihat Informasi
                        while (true) {
                            displayViewMenu();
                            cin >> viewChoice;
                            cin.ignore();

                            switch (viewChoice) {
                                case 1: {
                                    cout << "ID Mobil: ";
                                    getline(cin, carID);
                                    manager.checkCarAvailability(carID);
                                    break;
                                }
                                case 2: {
                                    manager.viewAllCars();
                                    break;
                                }
                                case 3: {
                                    manager.viewAllRenters();
                                    break;
                                }
                                case 0:
                                    break;
                                default:
                                    cout << "Pilihan tidak valid!" << endl;
                            }
                            if (viewChoice == 0) break;
                        }
                        break;
                    }

                    case 5: {
                        string filename;
                        cout << "Masukkan nama file (default: data/input.txt): ";
                        getline(cin, filename);
                        if (filename.empty()) filename = "data/input.txt";
                        manager.loadFromFile(filename);
                        break;
                    }

                    case 6: {
                        string filename;
                        cout << "Masukkan nama file (default: data/output.txt): ";
                        getline(cin, filename);
                        if (filename.empty()) filename = "data/output.txt";
                        manager.saveToFile(filename);
                        break;
                    }

                    default:
                        cout << "Pilihan tidak valid!" << endl;
                }
            }
        }

        // Menu user
        else if (loggedInUser->getRole() == USER) {
            while (true) {
                displayUserMenu();
                cin >> mainChoice;
                cin.ignore();

                if (mainChoice == 0) {
                    authManager.logout();
                    break;
                }

                switch (mainChoice) {
                    case 1: {
                        // Lihat Daftar Mobil Tersedia
                        manager.viewAvailableCars();
                        break;
                    }

                    case 2: {
                        // Cari Mobil Berdasarkan Tipe
                        cout << "\nMasukkan tipe mobil (SUV/Sedan/MPV/Truck): ";
                        getline(cin, carType);
                        manager.searchCarByType(carType);
                        break;
                    }

                    case 3: {
                        // Sewa Mobil
                        cout << "\n--- Sewa Mobil ---" << endl;
                        cout << "ID Anda sebagai Penyewa: ";
                        getline(cin, renterID);
                        cout << "ID Mobil yang ingin disewa: ";
                        getline(cin, carID);
                        cout << "Jumlah Hari: ";
                        getline(cin, days);

                        Car* car = manager.findCar(carID);
                        if (car != NULL) {
                            manager.rentCar(renterID, carID, stoi(days), car->getDailyRate());
                        }
                        break;
                    }

                    case 4: {
                        // Lihat Riwayat Penyewaan
                        manager.viewRentalHistory();
                        break;
                    }

                    default:
                        cout << "Pilihan tidak valid!" << endl;
                }
            }
        }
    }

    return 0;
}
