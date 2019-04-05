# SoalShift_modul3_B03

## No1
Buatlah program C yang bisa menghitung faktorial secara parallel lalu menampilkan hasilnya secara berurutan

	Contoh:
		./faktorial 5 3 4
		3! = 6
		4! = 24
		5! = 120
	

Source Code : <a href="https://github.com/lutzid/SoalShift_modul3_B03/blob/master/Soal1/Soal1.c"> Soal1 </a> <br>
Jawab :
<ul>
	<li>Langkah pertama yang kami lakukan adalah dengan menghitung faktorial dari 0 sampai dengan 15, kenapa 15? Karena tipe data yang digunakan merupakan tipe integer/ long long integer, untuk integer sendiri kurang lebih hanya bisa sampai dengan 12 faktorial, sedangkan long long integer hanya bisa sampai kurang lebih 19 faktorial, dan apabila kita memasang terlalu mepet, nantinya ditakutkan bahwa akan terjadi overflow</li>
	<li>Langkah selanjutnya kami melakukan thread untuk setiap argumen yang ada kecuali argumen ke 0, karena argumen tersebut merupakan nama program yang dieksekusi.</li>
	<li>Pada fungsi threadnya, kami mendapatkan berapa nilai argumen tersebut apabila di convert ke integer, lalu memasukkan angka tersebut ke dalam key dari array, dan menambahkan array key tersebut</li>
	<li>Setelah melakukan thread, kami melakukan join_thread pada setiap argumen</li>
	<li>Setelah melakukan join_thread tersebut, kami print dari bilangan ke 0 sampai dengan ke 15, dan melakukan print setiap angka tersebut sebanyak kemunculan angka tersebut</li>
	
</ul>

## No2
Pada suatu hari ada orang yang ingin berjualan 1 jenis barang secara private, dia memintamu membuat program C dengan spesifikasi sebagai berikut:

    a. Terdapat 2 server: server penjual dan server pembeli
    b. 1 server hanya bisa terkoneksi dengan 1 client
    c. Server penjual dan server pembeli memiliki stok barang yang selalu sama
    d. Client yang terkoneksi ke server penjual hanya bisa menambah stok
        ▪ Cara menambah stok: client yang terkoneksi ke server penjual mengirim string “tambah” ke server lalu stok bertambah 1
    e. Client yang terkoneksi ke server pembeli hanya bisa mengurangi stok
        ▪ Cara mengurangi stok: client yang terkoneksi ke server pembeli mengirim string “beli” ke server lalu stok berkurang 1
    f. Server pembeli akan mengirimkan info ke client yang terhubung dengannya apakah transaksi berhasil atau tidak berdasarkan ketersediaan stok
        ▪ Jika stok habis maka client yang terkoneksi ke server pembeli akan mencetak “transaksi gagal”
        ▪ Jika stok masih ada maka client yang terkoneksi ke server pembeli akan mencetak “transaksi berhasil”
    g. Server penjual akan mencetak stok saat ini setiap 5 detik sekali
    h. Menggunakan thread, socket, shared memory

Source Code : 
<a href="https://github.com/lutzid/SoalShift_modul3_B03/blob/master/Soal2/soal2clientpembeli.c"> Soal2ClientPembeli </a> <br>
<a href="https://github.com/lutzid/SoalShift_modul3_B03/blob/master/Soal2/soal2clientpenjual.c"> Soal2ClientPenjual </a> <br>
<a href="https://github.com/lutzid/SoalShift_modul3_B03/blob/master/Soal2/soal2serverpembeli.c"> Soal2ServerPembeli </a> <br>
<a href="https://github.com/lutzid/SoalShift_modul3_B03/blob/master/Soal2/soal2serverpenjual.c"> Soal2ServerPenjual </a> <br>
Jawab :
<ul>
	<li>Langkah pertama kami membuat server penjual terlebih dahulu. Dimana didalamnya terdapat thread untuk melakukan print stock yang ada tiap 5 detik. Di kedua server baik server penjual dan server pembeli terdapat shared memory yang mana shared memory itu digunaan untuk menyimpan stock. Kemudian di server penjual akan mengecek command yang dikirimkan dari client penjual apabila command "tambah" maka stock ditambah dan akan output Command Benar di client. Apabila command tidak sesuai maka akan outputkan Command Salah di client.</li>
	<li>Kemudian untuk client penjual akan selalu melakukan loop untuk inputan command yang akan dikirimkan ke server penjual.</li>
	<li>Untuk server pembeli berisi shared memory untuk menyimpan stock kemudian mengecek command dari client apabila command berupa string beli dan stock lebih dari 0 maka akan mengirim pesan ke client berupa transaksi sukses dan stock berkurang 1. Apabila stock 0 maka akan mengirim pesan Transaksi gagal ke client. Apabila command salah maka server akan mengirim pesan ke client berupa string Command salah.</li>
	<li>Kemudian untuk client pembeli akan selalu melakukan loop untuk inputan command yang akan dikirimkan ke server pembeli.</li>
</ul>

## No3	
Agmal dan Iraj merupakan 2 sahabat yang sedang kuliah dan hidup satu kostan, sayangnya mereka mempunyai gaya hidup yang berkebalikan, dimana Iraj merupakan laki-laki yang sangat sehat,rajin berolahraga dan bangun tidak pernah kesiangan sedangkan Agmal hampir menghabiskan setengah umur hidupnya hanya untuk tidur dan ‘ngoding’. Dikarenakan mereka sahabat yang baik, Agmal dan iraj sama-sama ingin membuat satu sama lain mengikuti gaya hidup mereka dengan cara membuat Iraj sering tidur seperti Agmal, atau membuat Agmal selalu bangun pagi seperti Iraj. Buatlah suatu program C untuk menggambarkan kehidupan mereka dengan spesifikasi sebagai berikut:

    a. Terdapat 2 karakter Agmal dan Iraj
    b. Kedua karakter memiliki status yang unik
        ▪ Agmal mempunyai WakeUp_Status, di awal program memiliki status 0
        ▪ Iraj memiliki Spirit_Status, di awal program memiliki status 100
        ▪ Terdapat 3 Fitur utama
		    • All Status, yaitu menampilkan status kedua sahabat
			Ex: Agmal WakeUp_Status = 75 
		      Iraj Spirit_Status = 30
		    • “Agmal Ayo Bangun” menambah WakeUp_Status Agmal sebesar 15 point
		    • “Iraj Ayo Tidur” mengurangi Spirit_Status Iraj sebanyak 20 point
        ▪ Terdapat Kasus yang unik dimana:
            • Jika Fitur “Agmal Ayo Bangun” dijalankan sebanyak 3 kali, maka Fitur “Iraj Ayo Tidur” Tidak bisa dijalankan selama 10 detik (Dengan mengirim pesan ke sistem “Fitur Iraj Ayo Tidur disabled 10 s”)
            • Jika Fitur  “Iraj Ayo Tidur” dijalankan sebanyak 3 kali, maka Fitur “Agmal Ayo Bangun” Tidak bisa dijalankan selama 10 detik (Dengan mengirim pesan ke sistem “Agmal Ayo Bangun disabled 10 s”)
        ▪ Program akan berhenti jika Salah Satu :
            • WakeUp_Status Agmal >= 100 (Tampilkan Pesan “Agmal Terbangun,mereka bangun pagi dan berolahraga”)
            • Spirit_Status Iraj <= 0 (Tampilkan Pesan “Iraj ikut tidur, dan bangun kesiangan bersama Agmal”)

        ▪ Syarat Menggunakan Lebih dari 1 Thread

Source Code : <a href="https://github.com/lutzid/SoalShift_modul3_B03/blob/master/Soal3/Soal3.c"> Soal3 </a> <br>
Jawab :
<ul>
	<li>Langkah pertama yang kami lakukan adalah membuat thread untuk agmal dan iraj</li>
	<li>Setiap thread tersebut berguna untuk menambahkan/mengurangi status mereka tergantung pada perintah apa yang dijalankan</li>
	<li>Apabila sebuah perintah dijalankan sebanyak 3 kali (kecuali perintah "All Status"), maka perintah yang lain yang berlawanan (kecuali "All Status") tidak dapat dijalankan selama 10 detik, dengan cara apabila salah satu perintah (kecuali "All Status"), sudah dijalankan sebanyak 3 kali, maka kami me-set sebuah variabel yang berguna untuk menghitung telah berapa lama sebuah command tidak dapat dijalankan</li>
	<li>Program akan berjalan selama wake up status dari agmal masih kurang dari 100 atau spirit status dari iraj lebih dari 0</li>
	<li>Apabila sudah memenuhi salah satu syarat tersebut, maka keluar dari infinite loop tersebut dan mengeluarkan hasil sesuai kondisi yang diminta</li>
</ul>

## No4
Buatlah sebuah program C dimana dapat menyimpan list proses yang sedang berjalan (ps -aux) maksimal 10 list proses. Dimana awalnya list proses disimpan dalam di 2 file ekstensi .txt yaitu  SimpanProses1.txt di direktori /home/Document/FolderProses1 dan SimpanProses2.txt di direktori /home/Document/FolderProses2 , setelah itu masing2 file di  kompres zip dengan format nama file KompresProses1.zip dan KompresProses2.zip dan file SimpanProses1.txt dan SimpanProses2.txt akan otomatis terhapus, setelah itu program akan menunggu selama 15 detik lalu program akan mengekstrak kembali file KompresProses1.zip dan KompresProses2.zip 

	Dengan Syarat : 
	• Setiap list proses yang di simpan dalam masing-masing file .txt harus berjalan bersama-sama
	• Ketika mengkompres masing-masing file .txt harus berjalan bersama-sama
	• Ketika Mengekstrak file .zip juga harus secara bersama-sama
	• Ketika Telah Selesai melakukan kompress file .zip masing-masing file, maka program akan memberi pesan “Menunggu 15 detik untuk mengekstrak kembali”
	• Wajib Menggunakan Multithreading
	• Boleh menggunakan system
Source Code : <a href="https://github.com/lutzid/SoalShift_modul3_B03/blob/master/Soal4/soal4.c"> Soal4 </a> <br>
Jawab : 
<ul>
	<li>Langkah pertama yang kami lakukan yaitu membuat fungsi Simpan1 dan Simpan2 </li>
	<li>Di tiap fungsi terdapat pengecekan terlebih dahulu terhadap direktori FolderProses1 dan FolderProses2.</li>
	<li>Apabila folder belum ada maka kita buat directory tersebut.</li>
	<li>Kemudian kita cek lagi apakah file SimpanProses1.txt pada direktori FolderProses1 dan SimpanProses2.txt pada direktori FolderProses2 itu ada atau tidak.</li>
	<li>Apabila file ada maka kita hapus terlebih dahulu supaya data yang akan disimpan sebanyak 10 proses yang akan kita ambil sekarang.</li>
	<li>Lalu berikutnya kita mengeksekusi command "ps -aux | tail -n 10" dan dioutputkan ke direktori tujuan sesuai fungsi prosesnya.</li>
	<li>Kemudian kita buat fungsi Zip1 dan Zip2 yang digunakan untuk melakukan zip file SimpanProses1.txt dan SimpanProses2.txt dengan nama KompresProses1.zip dan KompresProses2.zip.</li>
	<li>Lalu kita hapus file SimpanProses1.txt dan SimpanProses2.txt".</li>
	<li>Kemudian fungsi berikutnya yaitu Unzip1 dan Unzip2 yang tugasnya melakukan unzip KompresProses1.zip dan KompresProses2.zip.</li>
	<li>Kemudian hapus file KompresProses1.zip dan KompresProses2.zip.</li>
	<li>Kemudian langkah yang kami lakukan yaitu membuat main function dimana kami membuat 6 thread. 2 thread yang pertama mengeksekusi fungsi Simpan1 dan Simpan2. 2 thread berikutnya mengeksekusi Zip1 dan Zip2. Kemudian 2 thread terakhir mengeksekusi Unzip1 dan Unzip2</li>
	<li>Setelah membuat thread tersebut kami pun menjoinkan tiap 2 thread yang telah dibuat tadi supaya tiap 2 thread bisa berjalan secara bersamaan.</li>
</ul>

## No5
Angga, adik Jiwang akan berulang tahun yang ke sembilan pada tanggal 6 April besok. Karena lupa menabung, Jiwang tidak mempunyai uang sepeserpun untuk membelikan Angga kado. Kamu sebagai sahabat Jiwang ingin membantu Jiwang membahagiakan adiknya sehingga kamu menawarkan bantuan membuatkan permainan komputer sederhana menggunakan program C. Jiwang sangat menyukai idemu tersebut. Berikut permainan yang Jiwang minta. 

    a. Pemain memelihara seekor monster lucu dalam permainan. Pemain dapat  memberi nama pada monsternya. 
    b. Monster pemain memiliki hunger status yang berawal dengan nilai 200 (maksimalnya) dan nanti akan berkurang 5 tiap 10 detik.Ketika hunger status mencapai angka nol, pemain akan kalah. Hunger status dapat bertambah 15 apabila pemain memberi makan kepada monster, tetapi banyak makanan terbatas dan harus beli di Market.
    c. Monster pemain memiliki hygiene status yang berawal dari 100 dan nanti berkurang 10 tiap 30 detik. Ketika hygiene status mencapai angka nol, pemain akan kalah. Hygiene status' dapat bertambah 30 hanya dengan memandikan monster. Pemain dapat memandikannya setiap 20 detik(cooldownnya 20 detik).
    d. Monster pemain memiliki health status yang berawal dengan nilai 300. Variabel ini bertambah (regenerasi)daa 5 setiap 10 detik ketika monster dalam keadaan standby.
    e. Monster pemain dapat memasuki keadaan battle. Dalam keadaan ini, food status(fitur b), hygiene status'(fitur c), dan ‘regenerasi’(fitur d) tidak akan berjalan. Health status dari monster dimulai dari darah saat monster pemain memasuki battle. Monster pemain akan bertarung dengan monster NPC yang memiliki darah 100. Baik monster pemain maupun NPC memiliki serangan sebesar 20. Monster pemain dengan monster musuh akan menyerang secara bergantian. 
    f. Fitur shop, pemain dapat membeli makanan sepuas-puasnya selama stok di toko masih tersedia.
        ▪ Pembeli (terintegrasi dengan game)
            • Dapat mengecek stok makanan yang ada di toko.
            • Jika stok ada, pembeli dapat membeli makanan.
        ▪ Penjual (terpisah)
            • Bisa mengecek stok makanan yang ada di toko
            • Penjual dapat menambah stok makanan.

Spesifikasi program:
A. Program mampu mendeteksi input berupa key press. (Program bisa berjalan tanpa perlu menekan tombol enter)
B. Program terdiri dari 3 scene yaitu standby, battle, dan shop.
C. Pada saat berada di standby scene, program selalu menampilkan health status, hunger status, hygiene status, stok makanan tersisa, dan juga status kamar mandi (“Bath is ready” jika bisa digunakan, “Bath will be ready in [bath cooldown]s” jika sedang cooldown). Selain itu program selalu menampilkan 5 menu, yaitu memberi makan, mandi, battle, shop, dan exit. Contoh :

	Standby Mode
	Health : [health status]
	Hunger : [hunger status]
	Hygiene : [hygiene status]
	Food left : [your food stock]
	Bath will be ready in [cooldown]s
	Choices
    1. Eat
    2. Bath
    3. Battle
    4. Shop
    5. Exit

D. Pada saat berada di battle scene, program selalu menampilkan health status milik pemain dan monster NPC. Selain itu, program selalu menampilkan 2 menu yaitu serang atau lari. Contoh :

	Battle Mode
	Monster’s Health : [health status]
	Enemy’s Health : [enemy health status]
	Choices
    1. Attack
    2. Run

E. Pada saat berada di shop scene versi pembeli, program selalu menampilkan food stock toko dan milik pemain. Selain itu, program selalu menampilkan 2 menu yaitu beli dan kembali ke standby scene. Contoh :

	Shop Mode
	Shop food stock : [shop food stock]
	Your food stock : [your food stock]
	Choices
    1. Buy
    2. Back

F. Pada program penjual, program selalu menampilkan food stock toko. Selain itu, program juga menampilkan 2 menu yaitu restock dan exit. Contoh :

	Shop
	Food stock : [shop food stock]
	Choices
    1. Restock
    2. Exit

G. Pastikan terminal hanya mendisplay status detik ini sesuai scene terkait (hint: menggunakan system(“clear”))

Source Code : <a href="https://github.com/lutzid/SoalShift_modul3_B03/blob/master/Soal5/Soal5.c">Soal5</a> & <a href="https://github.com/lutzid/SoalShift_modul3_B03/blob/master/Soal5/Soal5Shop.c">Soal 5 Shop</a><br>
Jawab :

Pada soal ini terdapat 2 program yang dibuat, yaitu
### 1. Program Game
<ul>
	<li>Langkah pertama yang kami lakukan adalah membuat 3 thread yaitu thread pada kondisi standby, battle, dan shop dan membuat fungsi untuk 3 kondisi tersebut</li>
	<li>Untuk fungsi standby sendiri, kami melakukan print sesuai format yang ada, lalu setelah itu apabila memilih pilihan 1 atau 2, dia akan menambahkan hunger atau bath status sesuai dengan pilihan yang dipilih, apabila yang dipilih merupakan pilihan 3 atau 4, maka akan pindah ke menu yang diminta, dan apabila memilih pilihan 5, maka akan keluar dari program.</li>
	<li>Pada fungsi battle, apabila memilih pilihan 1, maka akan mengurangi darah 20 pada setiap monster (monster milik kita dan monster musuh) apabila salah satu darah dari monster kurang dari sama dengan 20, maka akan keluar dan pindah ke menu standby, tapi apabila memilih pilihan 2, maka akan langsung pindah ke menu standby</li>
	<li>Pada fungsi shop sendiri, apabila kita memilih pilihan 1 (beli), maka food stock user akan bertambah dan food stock dari toko akan berkurang dan akan berefek pada food stok dari toko pada program shop, apabila memilih pilihan kedua maka akan pindah ke standby menu</li>
	<li>Apabila terjadi perubahan yaitu dengan ditandai memilih salah satu pilihan, maka akan dilakukan refresh pada terminal</li>
	<li>Apabila memilih pilihan kedua pada menu standby, maka akan terjadi cooldown dan setiap detiknya akan dilakukan refresh pada terminal</li>
	<li>Apabila hunger status sudah melebihi batas maksimal, maka hunger status akan langsung di set pada nilai 200, karena tidak dapat bertambah lagi, apabila hunger status dan atau bath status saat terjadi pengurangan bernilai kurang dari sama dengan 0, maka status diset 0, dan tidak dapat menjadi negatif atau kurang dari 0</li>
</ul>

### 2. Shop
<ul>
	<li>Langkah pertama yang kami lakukan pada program ini adalah dengan membuat thread untuk menu shop pada program penjual ini</li>
	<li>Pada fungsi thread tersebut, apabila terjadi perubahan dengan ditandai memilih salah satu pilihan menu, maka akan dilakukan refresh pada terminal</li>
	<li>Pada fungsi tersebut juga, apabila memilih pilihan 1, maka akan menambah stok toko tersebut dan akan berefek pada stok toko yang ada di program game dengan memanfaatkan shared memory, tapi apabila memilih pilihan 2, maka akan keluar dari program tersebut</li>
</ul>
