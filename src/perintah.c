#include <stdio.h>
#include "perintah.h"
#include "pengguna.h"


void perintah(){
    // definisi perintah
    char * Daftar = "DAFTAR";
    char * Masuk = "MASUK";
    char * Keluar = "KELUAR";
    char * Tutup_program = "TUTUP_PROGRAM";
    char * Ganti_profil = "GANTI_PROFIL";
    char * Lihat_profil = "LIHAT_PROFIL";
    char * Atur_jenis_akun = "ATUR_JENIS_AKUN";
    char * Ubah_foto_profil = "UBAH_FOTO_PROFIL";
    char * Daftar_teman = "DAFTAR_TEMAN";
    char * Hapus_teman = "HAPUS_TEMAN";
    char * Daftar_permintaan_pertemanan = "DAFTAR_PERMINTAAN_PERTEMANAN";
    char * Setujui_pertemanan = "SETUJUI_PERTEMANAN";
    char * Kicau = "KICAU";
    char * Kicauan = "KICAUAN";
    char * Suka_kicauan = "SUKA_KICAUAN";
    char * Ubah_kicauan = "UBAH_KICAUAN";
    char * Balas = "BALAS";
    char * Balasan = "BALASAN";
    char * Hapus_balasan = "HAPUS_BALASAN";
    char * Buat_draf = "BUAT_DRAF";
    char * Lihat_draf = "LIHAT_DRAF";
    char * Utas = "UTAS";
    char * Sambung_utas = "SAMBUNG_UTAS";
    char * Hapus_utas = "HAPUS_UTAS";
    char * Cetak_utas = "CETAK_UTAS";
    char * Simpan = "SIMPAN";
    char * Muat = "MUAT";
    isLogin = FALSE;
    printf(">> ");
    STARTWORD();
    while(!(isWordEqualString(currentWord, Tutup_program))){
        if(!(isLogin)){
            printf("\n");
            // belum login
            if(isWordEqualString(currentWord, Masuk)){
                printf("jalankan perintah masuk\n");
                masuk();
                isLogin = TRUE;
            } else if(isWordEqualString(currentWord, Keluar)){
                printf("Anda belum login! Masuk terleibh dahulu\n");
            } else if(isWordEqualString(currentWord, Daftar)){
                daftar();
                printf("jalankan printah Daftar\n");
            } else if(isWordEqualString(currentWord, Simpan)){
                // Simpan();
                printf("jalankan perintah simpan\n");
            } else if(isWordEqualString(currentWord, Muat)){
                // Muat();
                printf("jalankan perintah muat\n");
            }
        } else{
            // sudah login
            Word current_pengguna = SELMT(dataNama,current_id);

            // Masuk 
            if(isWordEqualString(currentWord, Masuk)){                        
                printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
                
            }
            else if(isWordEqualString(currentWord,Daftar)){
                printf("Anda sudah masuk. Keluar terlebih dahulu untuk\nmelakukan daftar.\n");
            }

            // Keluar    
            else if(isWordEqualString(currentWord, Keluar)){
                printf("Anda berhasil logout. \nSampai jumpa di pertemuan berikutnya!\n");
                keluar();

            // Ganti Profil    
            } else if(isWordEqualString(currentWord, Ganti_profil)){
                gantiProfil(current_pengguna);

            // Lihat Profil    
            } else if(isWordEqualString(currentWord, Lihat_profil)){
                CopyWordWithSpace();
                lihatProfil(currentWord);
                printf("jalankan perintah lihat_profil\n");

            // Atur Jenis Akun    
            } else if(isWordEqualString(currentWord, Atur_jenis_akun)){
                aturJenisAkun(current_pengguna);
                printf("jalankan perintah atur_jenis_akun\n");

            // Ubah Foto Profil    
            } else if(isWordEqualString(currentWord, Ubah_foto_profil)){
                printf("jalankan perintah ubah_foto_profil");
                ubahFotoProfil(current_pengguna);

            // Display Daftar Teman    
            } else if(isWordEqualString(currentWord, Daftar_teman)){
                Daftar_Teman(matPertemanan);

            // Hapus Pertemanan    
            } else if(isWordEqualString(currentWord, Hapus_teman)){
                Hapus_Teman(&matPertemanan);
            } 

            // Display Daftar Permintaan Pertemanan
             else if(isWordEqualString(currentWord, Daftar_permintaan_pertemanan)){
                   //Daftar permintaan
                printf("jalankan perintah daftar_permintaan_pertemanan\n");

            // Accept Pertemanan    
            } else if(isWordEqualString(currentWord, Setujui_pertemanan)){
                //Setuju Permintaan
                printf("jalankan perintah setujui_pertemanan\n");

            // Input Kicau
            } else if(isWordEqualString(currentWord, Kicau)){
                inputKicau(list_kicau);
                printf("jalankan perintah kicau");

            // Display Kicauan    
            } else if(isWordEqualString(currentWord, Kicauan)){
                DisplayKicauan(list_kicau,current_id);
                printf("jalankan perintah kicauan\n");

            // Menyukai Kicauan    
            } else if(isWordEqualString(currentWord, Suka_kicauan)){
                ADVWORD();
                int idx = toInt(currentWord);
                sukaKicauan(idx, list_kicau);
                printf("jalankan perintah suka_kicauan\n");

            // Mengubah Kicauan    
            } else if(isWordEqualString(currentWord, Ubah_kicauan)){
                ADVWORD();
                int idx = toInt(currentWord);
                ubah_kicauan(idx,list_kicau);
                printf("jalankan perintah ubah_kicauan");

                
            } else if(isWordEqualString(currentWord, Balas)){
                printf("jalankan perintah balas\n");
            } else if(isWordEqualString(currentWord, Balasan)){
                printf("jalankan perintah balasan\n");
            } else if(isWordEqualString(currentWord, Hapus_balasan)){
                printf("jalankan perintah hapus_balasan");
            } else if(isWordEqualString(currentWord, Buat_draf)){
                printf("jalankan perintah buat_draf");
            } else if(isWordEqualString(currentWord, Lihat_draf)){
                printf("jalankan perintah lihat_draf\n");
            } else if(isWordEqualString(currentWord, Utas)){
                printf("jalankan perintah utas\n");
            } else if(isWordEqualString(currentWord, Sambung_utas)){
                printf("jalankan perintah sambung_utas\n");
            } else if(isWordEqualString(currentWord, Hapus_utas)){
                printf("jalankan perintah hapus utas\n");
            } else if(isWordEqualString(currentWord, Cetak_utas)){
                printf("jalankan perintah cetak_utas\n");
            } else if(isWordEqualString(currentWord, Simpan)){
                printf("jalankan perintah simpan\n");
            } else if(isWordEqualString(currentWord, Muat)){
                printf("jalankan perintah muat\n");
            }

        }
        printf(">> ");
        STARTWORD();
    }
}