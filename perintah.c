#include <stdio.h>
#include "wordmachine.c"
#include "boolean.h"
#include "charmachine.c"

int main(){
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
    char * Batal_tambah_teman = "BATAL_TAMBAH_TEMAN";
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
    boolean logged_in = FALSE;
    printf(">> ");
    STARTWORD();
    while(!(isWordEqualString(currentWord, Tutup_program))){
        if(!(logged_in)){
            // belum login
            if(isWordEqualString(currentWord, Masuk)){
                printf("jalankan perintah masuk\n");
                logged_in = TRUE;
            } else if(isWordEqualString(currentWord, Keluar)){
                printf("Anda belum login! Masuk terleibh dahulu\n");
            } else if(isWordEqualString(currentWord, Daftar)){
                printf("jalankan printah Daftar\n");
            } else if(isWordEqualString(currentWord, Simpan)){
                printf("jalankan perintah simpan\n");
            } else if(isWordEqualString(currentWord, Muat)){
                printf("jalankan perintah muat\n");
            }
        } else{
            // sudah login
            if(isWordEqualString(currentWord, Masuk)){
                printf("Wah Anda sudah masuk. Keluar dulu yuk!\n");
            } else if(isWordEqualString(currentWord, Keluar)){
                printf("Anda berhasil logout. \nSampai jumpa di pertemuan berikutnya!\n");
                logged_in = FALSE;
            } else if(isWordEqualString(currentWord, Ganti_profil)){
                printf("jalanakan perintah ganti_profil\n");
            } else if(isWordEqualString(currentWord, Lihat_profil)){
                printf("jalankan perintah lihat_profil\n");
            } else if(isWordEqualString(currentWord, Atur_jenis_akun)){
                printf("jalankan perintah atur_jenis_akun\n");
            } else if(isWordEqualString(currentWord, Ubah_foto_profil)){
                printf("jalankan perintah ubah_foto_profil");
            } else if(isWordEqualString(currentWord, Daftar_teman)){
                printf("jalankan perintah daftar_teman\n");
            } else if(isWordEqualString(currentWord, Hapus_teman)){
                printf("jalankan perintah hapus_teman\n");
            } else if(isWordEqualString(currentWord, Batal_tambah_teman)){
                printf("jalankan perintah batal_tambah_teman\n");
            } else if(isWordEqualString(currentWord, Daftar_permintaan_pertemanan)){
                printf("jalankan perintah daftar_permintaan_pertemanan\n");
            } else if(isWordEqualString(currentWord, Setujui_pertemanan)){
                printf("jalankan perintah setujui_pertemanan\n");
            } else if(isWordEqualString(currentWord, Kicau)){
                printf("jalankan perintah kicau");
            } else if(isWordEqualString(currentWord, Kicauan)){
                printf("jalankan perintah kicauan\n");
            } else if(isWordEqualString(currentWord, Suka_kicauan)){
                printf("jalankan perintah suka_kicauan\n");
            } else if(isWordEqualString(currentWord, Ubah_kicauan)){
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
    return 0;
}