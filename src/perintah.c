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
    char * TAMBAH_teman = "TAMBAH_TEMAN";
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
    char * Simpan_word = "SIMPAN";
    char * Muat = "MUAT";
    isLogin = FALSE;
    printf(">> ");
    STARTWORD();
    while(!(isWordEqualString(currentWord, Tutup_program))){
        //DEBUGGING PURPOSES
        char * nama = "CHECKDATA";
        if(isWordEqualString(currentWord,nama)){
            printf("\n======================== DATA PENGGUNA ========================\n");
            printf("current id: \n");
            printf("%d\n",current_id);
            printf("Jumlah Pengguna: \n");
            printf("%d\n",banyak_pengguna);
            printf("Is Login: \n");
            printf("%d\n",isLogin);
            printf("Data Nama: \n");
            SwprintList(dataNama);
            printf("\n\n");
            printf("Data Password: \n");
            SwprintList(password);
            printf("\n\n");
            printf("Data bio: \n"    );
            SwprintList(bio);
            printf("\n\n");
            printf("Data telepon: \n");
            SwdprintList(phone);
            printf("\n\n");
            printf("Data Weton: \n");
            SwprintList(Weton);
            printf("\n\n");
            printf("Data Jenis Akun: \n");
            SprintList(JenisAkun);
            printf("\n\n");
            printf("Data Profil: \n");
            int i;
            for(i = 0; i < SwlistLength(dataNama); i++){
                displayMatrixCharColoured(LSMELMT(profil,i));
                printf("\n");
            }
            printf("\n\n");
            printf("\n======================== DATA PERTEMANAN ========================\n");
            printf("Data Pertemanan: \n");
            PrintAdjMatrix(matPertemanan);
            printf("Jumlah Permintaan pertemanan: \n");
            printf("%d\n",addFriendCounter);
            printf("Display Permintaan pertmanan: \n");
            for(i = 0; i < addFriendCounter; i++){
                printf("Pengirim: ");
                printWord(permintaanTeman.array[i].pengirim);
                printf("| Penerima: ");
                printWord(permintaanTeman.array[i].penerima);
                printf("| Kepopuleran: %d\n",permintaanTeman.array[i].kepopuleran);
            }

            printf("\n======================== DATA KICAUAN ========================\n");
            printf("Jumlah kicau \n");
            printf("%d\n",jumlah_kicau);
            printf("Daftar Kicau \n");
            for(i = 0; i < jumlah_kicau; i++){
                printDataKicauan(KELMT(list_kicau,i));
                printf("test: \n");
            }
            

            printf("\n======================== DATA BALASAN ========================\n");
            printf("Jumlah Kicau yang punya Balasan: \n");
            printf("%d\n",jumlah_balasan);

            printf("Display Balasan: \n");
            for(i = 0; i < jumlah_kicau; i++){
                if (hasChild(BELMT(list_balasan,i)))
                {
                    printf("Kicauan dengan ID %d yang dibuat oleh ",BID(Root(BELMT(list_balasan,i))));                
                    printWord(BAUTH(Root(BELMT(list_balasan,i))));
                    printf("\n\n");
                    displayTreeFull(BELMT(list_balasan,i));
                    printf("\n");
                }
                
            }

            printf("\n======================== DATA DRAF ========================\n");
            printf("Jumlah Pengguna yang punya Draf: \n");
            printf("%d\n",jumlah_Draf);
            printf("Display Draf: \n");
            for(i = 0; i < SwlistLength(dataNama); i++){
                ListStatikStack temps = draf;
                if(!IsEmpty(LSSELMT(temps,i))){
                    int j = 1;
                    printf("Untuk Draf Pengguna : ");
                    printWord(SELMT(dataNama,i));
                    printf("\n");
                    Stack _current_Stack = LSSELMT(temps,i);
                    while(!IsEmpty(_current_Stack)){
                        infotype _temps_text;
                        infodate _temps_date;
                        Pop(&_current_Stack,&_temps_text,&_temps_date);
                        printf("Draf ke %d: \n",j);
                        printf("Text: \n");
                        printWord(_temps_text);
                        printf("\nDate: \n");
                        TulisDATETIME(_temps_date);
                        printf("\n");
                        j++;
                    }
                }
            }
            printf("\n======================== DATA UTAS ========================\n");
            printf("Jumlah Kicau yang punya utas: \n");
            printf("%d\n",listLengthDinUtas(utas_pointers)); // jumlah utas = panjang list dinamis utasan

            printf("Display ListUtas: \n");


            // akses data utas dari list dinamis
            for(i = 0; i < listLengthDinUtas(utas_pointers); i++){
                printf("h\n");
                
                CetakUtas(ELMTD_LDU(utas_pointers, i));
                // Address lk = ELMTD_LDU(utas_pointers, i);
                // CetakUtas(lk);

                // if(KELMT(list_kicau,i).next_Utas != NULL){
                //     printf("Utas pada kicau id: %d\n",KELMT(list_kicau,i).id);
                //     Address p = ELMTD_LDU(utas_pointers,i);
                //     while (p != NULL)
                //     {
                //         printf("id: %d",p->IdUtas);
                //         printf("Author: \n");
                //         printWord(p->Author);
                //         printf("Text: \n");
                //         printWord(p->texts);
                //         printf("Datetime: \n");
                //         TulisDATETIME(p->dateTime);
                //         p = NEXT(p);
                //     }
                    
                // }
            }
        }
    
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
            } else if(isWordEqualString(currentWord, Simpan_word)){
                Simpan();
                printf("jalankan perintah simpan\n");
            } else if(isWordEqualString(currentWord, Muat)){
                // Muat();
                printf("jalankan perintah muat\n");
            }
            else{
                printf("Perintah Tidak ditemukan \n");
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
                IgnoreEnters();
                IgnoreBlanks();
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
            else if(isWordEqualString(currentWord,TAMBAH_teman)){
                // sendFriendRequest(&permintaanTeman, )
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
                inputKicau(&list_kicau);
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
                ADVWORD();
                int idkicau = toInt(currentWord);
                ADVWORD();
                int idbalasan = toInt(currentWord);
                inputBalas(&list_balasan,idkicau,idbalasan);
                

            } else if(isWordEqualString(currentWord, Balasan)){
                printf("jalankan perintah balasan\n");
                ADVWORD();
                int idkicau = toInt(currentWord);
                displayBalasan(list_balasan,idkicau);

            } else if(isWordEqualString(currentWord, Hapus_balasan)){
                printf("jalankan perintah hapus_balasan\n");
                ADVWORD();
                int idkicau = toInt(currentWord);
                ADVWORD();
                int idbalasan = toInt(currentWord);
                hapusBalasan(&list_balasan,idkicau,idbalasan);

            } else if(isWordEqualString(currentWord, Buat_draf)){
                buatDraf(current_pengguna);
                printf("jalankan perintah buat_draf");
            } else if(isWordEqualString(currentWord, Lihat_draf)){
                lihatDraf(current_pengguna);
                printf("jalankan perintah lihat_draf\n");
            } else if(isWordEqualString(currentWord, Utas)){
                printf("jalankan perintah utas\n");
                ADVWORD();
                int idkicau = toInt(currentWord);
                printf("idkicau: %d\n", idkicau);
                printf("len: %d\n", currentWord.Length);
                CreateRootUtas(idkicau);
            } else if(isWordEqualString(currentWord, Sambung_utas)){
                printf("jalankan perintah sambung_utas\n");
                ADVWORD();
                int idutas = toInt(currentWord);
                printf("idutas: %d\n", idutas);
                printf("len: %d\n", currentWord.Length);
                ADVWORD();
                int indeks = toInt(currentWord);
                printf("indeks: %d\n", indeks);
                printf("len: %d\n", currentWord.Length);
                SambungUtas(idutas, indeks);
            } else if(isWordEqualString(currentWord, Hapus_utas)){
                printf("jalankan perintah hapus utas\n");
                ADVWORD();
                int idutas = toInt(currentWord);
                printf("idutas: %d\n", idutas);
                printf("len: %d\n", currentWord.Length);
                ADVWORD();
                int indeks = toInt(currentWord);
                printf("indeks: %d\n", indeks);
                printf("len: %d\n", currentWord.Length);
                DeleteUtas(idutas, indeks);
            } else if(isWordEqualString(currentWord, Cetak_utas)){
                printf("jalankan perintah cetak_utas\n");
                ADVWORD();
                int idutas = toInt(currentWord);
                printf("idutas: %d\n", idutas);
                printf("len: %d\n", currentWord.Length);
                CetakUtas(utas_pointers.buffer[idutas-1]);
            } else if(isWordEqualString(currentWord, Simpan_word)){
                Simpan();
                printf("jalankan perintah simpan\n");
            } else if(isWordEqualString(currentWord, Muat)){
                printf("jalankan perintah muat\n");
            } 

        }
        printf(">> ");
        STARTWORD();
    }
}