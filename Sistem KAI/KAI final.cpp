#include<iostream>
#include <fstream>
#include "loginn.h"
#include "ktp1.h"

using namespace std;

//materi pertemuan 1 class
class jadwalKereta{
public:
	//materi pertemuan 2 array statis
	string stasiunAsal [20] = {
    "Stasiun Lhokseumawe", 
    "Stasiun Lhokseumawe", 
    "Stasiun Lhokseumawe", 
    "Stasiun Banda Aceh", 
    "Stasiun Banda Aceh", 
    "Stasiun Banda Aceh", 
    "Stasiun Lhokseumawe", 
    "Stasiun Lhokseumawe", 
    "Stasiun Banda Aceh", 
    "Stasiun Banda Aceh", 
    "Stasiun Lhokseumawe", 
    "Stasiun Banda Aceh", 
    "Stasiun Lhokseumawe", 
    "Stasiun Lhokseumawe", 
    "Stasiun Banda Aceh", 
    "Stasiun Banda Aceh", 
    "Stasiun Lhokseumawe", 
    "Stasiun Lhokseumawe", 
    "Stasiun Banda Aceh", 
    "Stasiun Banda Aceh",
	};

	
	string stasiunTujuan [20] = {
    "Stasiun Medan",
    "Stasiun Tebing Tinggi",
    "Stasiun Binjai",
    "Stasiun Medan",
    "Stasiun Tebing Tinggi",
    "Stasiun Binjai",
    "Stasiun Padang",
    "Stasiun Pariaman",
    "Stasiun Padang",
    "Stasiun Pariaman",
    "Stasiun Pekanbaru",
    "Stasiun Pekanbaru",
    "Stasiun Palembang",
    "Stasiun Lubuk Linggau",
    "Stasiun Palembang",
    "Stasiun Lubuk Linggau",
    "Stasiun Tanjung Karang",
    "Stasiun Kotabumi",
    "Stasiun Tanjung Karang",
    "Stasiun Kotabumi",
	};
	
	string kodeKereta[20] = {
    "KA001",
    "KA002",
    "KA003",
    "KA004",
    "KA005",
    "KA006",
    "KA007",
    "KA008",
    "KA009",
    "KA010",
    "KA011",
    "KA012",
    "KA013",
    "KA014",
    "KA015",
    "KA016",
    "KA017",
    "KA018",
    "KA019",
    "KA020"
};

	string namaKereta[20] = {
    "Malabar Jaya - Bisnis",
    "Cut Meutia Indah - Premium",
    "Bima Utama - Eksekutif",
    "Cut Meutia Utama - Eksekutif",
    "Bima Utama - Premium",
    "Malabar Cepat - Eksekutif",
    "Bima Jaya - Premium",
    "Argo Express - Eksekutif",
    "Tidar Utama - Premium",
    "Argo Express - Eksekutif",
    "Bima Utama - Commuter",
    "Mandalika Indah - Lokal",
    "Tidar Utama - Eksekutif",
    "Sriwijaya Express - Premium",
    "Parahyangan Express - Ekonomi",
    "Gajayana Indah - Premium",
    "Malabar Indah - Commuter",
    "Parahyangan Utama - Premium",
    "Cut Meutia Express - Commuter",
    "Gajayana Indah - Bisnis"
};

	string jadwalKereta[20] = {
    "11:47 - 00:53",
    "10:02 - 08:04",
    "05:15 - 14:52",
    "04:50 - 15:06",
    "02:19 - 21:40",
    "17:23 - 07:42",
    "23:07 - 11:11",
    "15:06 - 13:11",
    "07:10 - 06:27",
    "03:07 - 19:25",
    "18:10 - 11:41",
    "12:44 - 08:03",
    "15:13 - 19:04",
    "19:44 - 22:16",
    "21:41 - 07:23",
    "13:54 - 18:20",
    "02:14 - 23:51",
    "00:50 - 12:24",
    "15:27 - 17:37",
    "08:48 - 13:27"
};

	string ruteProvinsi[20] = {
    "Aceh -> Sumatera Utara",
    "Aceh -> Sumatera Utara",
    "Aceh -> Sumatera Utara",
    "Aceh -> Sumatera Utara",
    "Aceh -> Sumatera Utara",
    "Aceh -> Sumatera Utara",
    "Aceh -> Sumatera Barat",
    "Aceh -> Sumatera Barat",
    "Aceh -> Sumatera Barat",
    "Aceh -> Sumatera Barat",
    "Aceh -> Riau",
    "Aceh -> Riau",
    "Aceh -> Sumatera Selatan",
    "Aceh -> Sumatera Selatan",
    "Aceh -> Sumatera Selatan",
    "Aceh -> Sumatera Selatan",
    "Aceh -> Lampung",
    "Aceh -> Lampung",
    "Aceh -> Lampung",
    "Aceh -> Lampung"
};

	int hargaTiket[20] = {
    828248,
    901416,
    913009,
    516066,
    152430,
    157507,
    297481,
    220800,
    158390,
    852498,
    729004,
    795346,
    961513,
    460288,
    370609,
    147525,
    319779,
    133392,
    430857,
    709155
};


	//materi pertemuan 1 rekursi
	void tampilkanJadwal(int index) {
	    if (index == 20) return; 
	
	    cout << index + 1 << ". | " << kodeKereta[index] << " | " << stasiunAsal[index] << " -> " << stasiunTujuan[index] << endl;
	    cout << "   Provinsi : " << ruteProvinsi[index] << endl;
	    cout << "   Kereta   : " << namaKereta[index] << endl;
	    cout << "   Pukul    : " << jadwalKereta[index] << endl;
	    cout << "   Harga    : Rp " << hargaTiket[index] << endl << endl;
	
	    tampilkanJadwal(index + 1); 
	}
	
	void cariNamaKereta(string nama) {
	    bool ditemukan = false;
	    cout << "\n=== HASIL PENCARIAN KERETA (SUMATERA) ===\n";
	
	    for (int i = 0; i < 20; i++) {
	        if (namaKereta[i].find(nama) != string::npos) {
	            ditemukan = true;
	            cout << i + 1 << ". | " << kodeKereta[i] << " | "
	                 << stasiunAsal[i] << " -> " << stasiunTujuan[i] << endl;
	            cout << "   Kereta   : " << namaKereta[i] << endl;
	            cout << "   Pukul    : " << jadwalKereta[i] << endl;
	            cout << "   Harga    : Rp " << hargaTiket[i] << endl;
	            cout << "----------------------------------------\n";
	        }
	    }
	
	    if (!ditemukan)
	        cout << "Tidak ditemukan kereta dengan nama \"" << nama << "\".\n";
	}


};

class jadwalKeretaJawa{
public:
	

	string kodeKeretaJawa[100] = {
	    "KA021",
	    "KA022",
	    "KA023",
	    "KA024",
	    "KA025",
	    "KA026",
	    "KA027",
	    "KA028",
	    "KA029",
	    "KA030",
	    "KA031",
	    "KA032",
	    "KA033",
	    "KA034",
	    "KA035",
	    "KA036",
	    "KA037",
	    "KA038",
	    "KA039",
	    "KA040",
	    "KA041",
	    "KA042",
	    "KA043",
	    "KA044",
	    "KA045",
	    "KA046",
	    "KA047",
	    "KA048",
	    "KA049",
	    "KA050",
	    "KA051",
	    "KA052",
	    "KA053",
	    "KA054",
	    "KA055",
	    "KA056",
	    "KA057",
	    "KA058",
	    "KA059",
	    "KA060",
	    "KA061",
	    "KA062",
	    "KA063",
	    "KA064",
	    "KA065",
	    "KA066",
	    "KA067",
	    "KA068",
	    "KA069",
	    "KA070",
	    "KA071",
	    "KA072",
	    "KA073",
	    "KA074",
	    "KA075",
	    "KA076",
	    "KA077",
	    "KA078",
	    "KA079",
	    "KA080",
	    "KA081",
	    "KA082",
	    "KA083",
	    "KA084",
	    "KA085",
	    "KA086",
	    "KA087",
	    "KA088",
	    "KA089",
	    "KA090",
	    "KA091",
	    "KA092",
	    "KA093",
	    "KA094",
	    "KA095",
	    "KA096",
	    "KA097",
	    "KA098",
	    "KA099",
	    "KA100",
	    "KA101",
	    "KA102",
	    "KA103",
	    "KA104",
	    "KA105",
	    "KA106",
	    "KA107",
	    "KA108",
	    "KA109",
	    "KA110",
	    "KA111",
	    "KA112",
	    "KA113",
	    "KA114",
	    "KA115",
	    "KA116",
	    "KA117",
	    "KA118",
	    "KA119",
	    "KA120",
	};
	
	
	string namaKeretaJawa[100] = {
	    "Argo Bromo Anggrek - Eksekutif",
	    "Taksaka - Eksekutif",
	    "Matarmaja - Ekonomi",
	    "Gajayana - Eksekutif",
	    "Lodaya - Bisnis",
	    "Turangga - Eksekutif",
	    "Argo Lawu - Eksekutif",
	    "Kertajaya - Ekonomi",
	    "Ciremai - Bisnis",
	    "Serayu - Ekonomi",
	    "Jayabaya - Ekonomi",
	    "Sancaka - Eksekutif",
	    "Argo Parahyangan - Eksekutif",
	    "Mutiara Selatan - Bisnis",
	    "Bangunkarta - Eksekutif",
	    "Tawang Jaya - Ekonomi",
	    "Argo Wilis - Eksekutif",
	    "Kutojaya Selatan - Ekonomi",
	    "KRL Commuter Line - Komuter",
	    "Prambanan Ekspres - Komuter",
	    "Malabar - Eksekutif",
	    "Sawunggalih - Ekonomi",
	    "Harina - Bisnis",
	    "Singasari - Ekonomi",
	    "Krakatau - Ekonomi",
	    "Wijayakusuma - Eksekutif",
	    "Gumarang - Bisnis",
	    "Argo Sindoro - Eksekutif",
	    "Argo Muria - Eksekutif",
	    "Kutojaya Utara - Ekonomi",
	    "Kahuripan - Ekonomi",
	    "Progo - Ekonomi",
	    "Brantas - Ekonomi",
	    "Argo Cheribon - Eksekutif",
	    "Siliwangi - Ekonomi",
	    "Pangandaran - Eksekutif",
	    "Singkarak - Ekonomi",
	    "Sri Tanjung - Ekonomi",
	    "Menoreh - Bisnis",
	    "Jaka Tingkir - Ekonomi",
	    "Argo Dwipangga - Eksekutif",
	    "Fajar Utama Yogya - Bisnis",
	    "Senja Utama Solo - Ekonomi",
	    "Kertanegara - Bisnis",
	    "Logawa - Ekonomi",
	    "Tawang Alun - Ekonomi",
	    "Argo Semeru - Eksekutif",
	    "Argo Merbabu - Eksekutif",
	    "Dharmawangsa - Ekonomi",
	    "Jayakarta - Ekonomi",
	    "Bima - Eksekutif",
	    "Argo Wilis - Eksekutif",
	    "Argo Parahyangan - Eksekutif",
	    "Mutiara Timur - Bisnis",
	    "Probowangi - Ekonomi",
	    "Rajabasa - Ekonomi",
	    "Bukit Serelo - Ekonomi",
	    "Sriwijaya - Eksekutif",
	    "Ambarawa Ekspres - Ekonomi",
	    "Jayanegara - Bisnis",
	    "Sawunggalih Malam - Ekonomi",
	    "Joglosemarkerto - Ekonomi",
	    "Argo Cirebon - Eksekutif",
	    "Argo Cheribon Malam - Eksekutif",
	    "Cikuray - Ekonomi",
	    "Wilis - Eksekutif",
	    "Pangrango - Ekonomi",
	    "Siliwangi Pagi - Ekonomi",
	    "Siliwangi Siang - Ekonomi",
	    "KRD Bojonegoro - Komuter",
	    "KRD Kertosono - Komuter",
	    "Kaligung - Ekonomi",
	    "Kamandaka - Ekonomi",
	    "Batara Kresna - Komuter",
	    "Metro Jaya - Eksekutif",
	    "Cikuray Malam - Ekonomi",
	    "Ciremai Siang - Bisnis",
	    "Jaka Tingkir Malam - Ekonomi",
	    "Bangunkarta Pagi - Eksekutif",
	    "Fajar Utama Solo - Bisnis",
	    "Sindoro Malam - Eksekutif",
	    "Argo Muria Pagi - Eksekutif",
	    "Sancaka Sore - Eksekutif",
	    "Malabar Malam - Eksekutif",
	    "Logawa Malam - Ekonomi",
	    "Progo Malam - Ekonomi",
	    "Serayu Malam - Ekonomi",
	    "Argo Lawu Malam - Eksekutif",
	    "Taksaka Malam - Eksekutif",
	    "Tegal Ekspres - Ekonomi",
	    "Sembrani - Eksekutif",
	    "Gumarang Siang - Bisnis",
	    "Sawunggalih Ekspres - Ekonomi",
	    "Tawang Jaya Premium - Ekonomi",
	    "Kertajaya Malam - Ekonomi",
	    "Majapahit - Ekonomi",
	    "Dharmawangsa Malam - Ekonomi",
	    "Argo Semeru Pagi - Eksekutif",
	    "Argo Bromo Pagi - Eksekutif",
	    "Argo Dwipangga Malam - Eksekutif",
	};
	
	
	string stasiunAsalJawa[100] = {
	    "Jakarta Gambir",
	    "Yogyakarta Tugu",
	    "Malang",
	    "Malang",
	    "Bandung",
	    "Bandung",
	    "Solo Balapan",
	    "Surabaya Pasarturi",
	    "Bandung",
	    "Purwokerto",
	    "Malang",
	    "Yogyakarta Tugu",
	    "Jakarta Gambir",
	    "Bandung",
	    "Jombang",
	    "Semarang Poncol",
	    "Bandung",
	    "Kutoarjo",
	    "Bogor",
	    "Kutoarjo",
	    "Bandung",
	    "Kutoarjo",
	    "Bandung",
	    "Blitar",
	    "Merak",
	    "Cilacap",
	    "Surabaya Pasarturi",
	    "Semarang Poncol",
	    "Jakarta Gambir",
	    "Kutoarjo",
	    "Blitar",
	    "Yogyakarta Tugu",
	    "Blitar",
	    "Jakarta Gambir",
	    "Sukabumi",
	    "Banjar",
	    "Padang",
	    "Lempuyangan",
	    "Semarang Poncol",
	    "Purwosari",
	    "Jakarta Gambir",
	    "Solo Balapan",
	    "Malang",
	    "Bandung",
	    "Purwokerto",
	    "Malang",
	    "Jakarta Gambir",
	    "Yogyakarta Tugu",
	    "Surabaya Pasarturi",
	    "Surabaya Gubeng",
	    "Surabaya Gubeng",
	    "Jakarta Gambir",
	    "Surabaya Gubeng",
	    "Jakarta Gambir",
	    "Semarang Poncol",
	    "Surabaya Gubeng",
	    "Kertapati",
	    "Lubuklinggau",
	    "Kertapati",
	    "Semarang Poncol",
	    "Surabaya Pasarturi",
	    "Cirebon",
	    "Cirebon",
	    "Garut",
	    "Bandung",
	    "Banjar",
	    "Padang",
	    "Lempuyangan",
	    "Solo Balapan",
	    "Purwosari",
	    "Solo Balapan",
	    "Jakarta Gambir",
	    "Semarang Poncol",
	    "Jakarta Gambir",
	    "Jakarta Gambir",
	    "Surabaya Gubeng",
	    "Surabaya Gubeng",
	    "Jakarta Gambir",
	    "Semarang Poncol",
	    "Bandung",
	    "Purwosari",
	    "Jakarta Gambir",
	    "Semarang Poncol",
	    "Jakarta Gambir",
	    "Jakarta Gambir",
	    "Surabaya Gubeng",
	    "Malang",
	    "Jakarta Gambir",
	    "Surabaya Gubeng",
	    "Jakarta Gambir",
	    "Jakarta Gambir",
	    "Jakarta Gambir",
	    "Jakarta Gambir",
	    "Jakarta Gambir",
	    "Jakarta Gambir",
	    "Jakarta Gambir",
	    "Jakarta Gambir",
	    "Jakarta Gambir",
	    "Jakarta Gambir",
	    "Jakarta Gambir",
	};
	
	
	string stasiunTujuanJawa[100] = {
	    "Surabaya Pasarturi",
	    "Jakarta Gambir",
	    "Jakarta Pasar Senen",
	    "Jakarta Gambir",
	    "Solo Balapan",
	    "Surabaya Gubeng",
	    "Jakarta Gambir",
	    "Jakarta Pasar Senen",
	    "Semarang Tawang",
	    "Jakarta Pasar Senen",
	    "Jakarta Pasar Senen",
	    "Surabaya Gubeng",
	    "Bandung",
	    "Surabaya Gubeng",
	    "Jakarta Gambir",
	    "Jakarta Pasar Senen",
	    "Surabaya Gubeng",
	    "Bandung",
	    "Jakarta Kota",
	    "Yogyakarta Tugu",
	    "Malang",
	    "Jakarta Pasar Senen",
	    "Surabaya Pasarturi",
	    "Jakarta Pasar Senen",
	    "Blitar",
	    "Banyuwangi",
	    "Jakarta Pasar Senen",
	    "Semarang Tawang",
	    "Semarang Tawang",
	    "Jakarta Pasar Senen",
	    "Bandung",
	    "Jakarta Pasar Senen",
	    "Jakarta Pasar Senen",
	    "Cirebon",
	    "Cianjur",
	    "Jakarta Gambir",
	    "Solok",
	    "Banyuwangi",
	    "Jakarta Pasar Senen",
	    "Jakarta Pasar Senen",
	    "Jakarta Gambir",
	    "Jakarta Pasar Senen",
	    "Kutoarjo",
	    "Bandung",
	    "Jember",
	    "Banyuwangi",
	    "Surabaya Gubeng",
	    "Bandung",
	    "Jakarta Pasar Senen",
	    "Bandung",
	    "Semarang Tawang",
	    "Jakarta Gambir",
	    "Bandung",
	    "Jakarta Gambir",
	    "Banyuwangi",
	    "Banyuwangi",
	    "Tanjungkarang",
	    "Kertapati",
	    "Tanjungkarang",
	    "Surabaya Pasarturi",
	    "Bandung",
	    "Jakarta Gambir",
	    "Kutoarjo",
	    "Cirebon",
	    "Surabaya Pasarturi",
	    "Jakarta Pasar Senen",
	    "Kutoarjo",
	    "Jakarta Pasar Senen",
	    "Solo Balapan",
	    "Jakarta Pasar Senen",
	    "Jakarta Gambir",
	    "Jakarta Gambir",
	    "Jakarta Pasar Senen",
	    "Solo Balapan",
	    "Jakarta Gambir",
	    "Jakarta Gambir",
	    "Surabaya Gubeng",
	    "Bandung",
	    "Surabaya Gubeng",
	    "Jakarta Pasar Senen",
	    "Jakarta Pasar Senen",
	    "Jakarta Pasar Senen",
	    "Jakarta Pasar Senen",
	    "Jakarta Pasar Senen",
	    "Jakarta Pasar Senen",
	    "Jakarta Pasar Senen",
	    "Jakarta Pasar Senen",
	    "Jakarta Pasar Senen",
	    "Jakarta Pasar Senen",
	    "Jakarta Pasar Senen",
	    "Jakarta Pasar Senen",
	    "Jakarta Pasar Senen",
	    "Jakarta Pasar Senen",
	    "Jakarta Pasar Senen",
	};
	
	
	string jadwalKeretaJawa[100] = {
	    "08:00 - 15:30",
	    "09:00 - 15:30",
	    "09:00 - 21:00",
	    "13:30 - 22:00",
	    "07:10 - 14:00",
	    "19:00 - 06:00",
	    "08:00 - 14:30",
	    "21:30 - 07:00",
	    "07:00 - 13:00",
	    "06:30 - 13:00",
	    "12:00 - 23:30",
	    "07:00 - 11:30",
	    "10:00 - 12:50",
	    "17:00 - 03:00",
	    "08:15 - 16:45",
	    "22:00 - 05:00",
	    "07:00 - 15:15",
	    "09:30 - 16:30",
	    "05:30 - 06:45",
	    "05:30 - 06:45",
	    "15:45 - 06:00",
	    "07:00 - 13:30",
	    "20:00 - 06:30",
	    "12:45 - 23:45",
	    "08:00 - 20:30",
	    "14:00 - 02:00",
	    "15:30 - 03:45",
	    "06:00 - 11:45",
	    "16:00 - 21:30",
	    "18:00 - 00:30",
	    "17:00 - 04:30",
	    "21:00 - 04:30",
	    "13:30 - 23:45",
	    "10:00 - 12:45",
	    "06:00 - 08:00",
	    "09:00 - 16:00",
	    "07:00 - 09:00",
	    "07:00 - 17:15",
	    "19:00 - 02:30",
	    "18:00 - 01:30",
	    "08:00 - 14:30",
	    "07:00 - 13:30",
	    "18:00 - 00:30",
	    "07:00 - 15:15",
	    "07:50 - 15:15",
	    "09:30 - 16:00",
	    "13:00 - 23:00",
	    "12:30 - 22:00",
	    "16:30 - 04:00",
	    "07:00 - 15:00",
	    "07:30 - 10:30",
	    "08:00 - 12:00",
	    "04:30 - 10:00",
	    "07:30 - 14:00",
	    "09:00 - 16:30",
	    "20:00 - 06:30",
	    "07:00 - 12:15",
	    "18:00 - 04:00",
	    "19:00 - 01:30",
	    "07:00 - 11:00",
	    "09:00 - 11:30",
	    "19:00 - 21:30",
	    "07:00 - 13:00",
	    "07:00 - 15:00",
	    "06:00 - 08:00",
	    "06:30 - 07:15",
	    "19:00 - 01:00",
	    "11:00 - 17:30",
	    "20:00 - 03:30",
	    "18:00 - 07:30",
	    "18:00 - 06:00",
	    "22:00 - 05:30",
	    "20:30 - 03:00",
	    "21:00 - 03:30",
	    "21:30 - 04:00",
	    "06:00 - 07:30",
	    "17:30 - 04:30",
	    "10:00 - 22:00",
	    "06:30 - 13:00",
	    "23:00 - 06:00",
	    "21:00 - 07:00",
	    "18:30 - 06:00",
	    "20:00 - 06:00",
	    "06:00 - 13:15",
	    "05:30 - 12:45",
	    "21:00 - 03:30",
	    "21:00 - 03:30",
	    "21:00 - 03:30",
	    "21:00 - 03:30",
	    "21:00 - 03:30",
	    "21:00 - 03:30",
	    "21:00 - 03:30",
	    "21:00 - 03:30",
	    "21:00 - 03:30",
	    "21:00 - 03:30",
	    "21:00 - 03:30",
	    "21:00 - 03:30",
	    "21:00 - 03:30",
	    "21:00 - 03:30",
	    "21:00 - 03:30",
	};
	
	
	string ruteProvinsiJawa[100] = {
	    "DKI Jakarta -> Jawa Timur",
	    "DI Yogyakarta -> DKI Jakarta",
	    "Jawa Timur -> DKI Jakarta",
	    "Jawa Timur -> DKI Jakarta",
	    "Jawa Barat -> Jawa Tengah",
	    "Jawa Barat -> Jawa Timur",
	    "Jawa Tengah -> DKI Jakarta",
	    "Jawa Timur -> DKI Jakarta",
	    "Jawa Barat -> Jawa Tengah",
	    "Jawa -> DKI Jakarta",
	    "Jawa Timur -> DKI Jakarta",
	    "DI Yogyakarta -> Jawa Timur",
	    "DKI Jakarta -> Jawa Barat",
	    "Jawa Barat -> Jawa Timur",
	    "Jawa Timur -> DKI Jakarta",
	    "Jawa Tengah -> DKI Jakarta",
	    "Jawa Barat -> Jawa Timur",
	    "Jawa Tengah -> Jawa Barat",
	    "Jawa Barat -> DKI Jakarta",
	    "Jawa Tengah -> DI Yogyakarta",
	    "Jawa Barat -> Jawa Timur",
	    "Jawa Tengah -> DKI Jakarta",
	    "Jawa Barat -> Jawa Timur",
	    "Jawa Timur -> DKI Jakarta",
	    "Banten -> Jawa Timur",
	    "Jawa Tengah -> Jawa Timur",
	    "Jawa Timur -> DKI Jakarta",
	    "Jawa Tengah -> Jawa Tengah",
	    "DKI Jakarta -> Jawa Tengah",
	    "Jawa Tengah -> DKI Jakarta",
	    "Jawa Timur -> Jawa Barat",
	    "DI Yogyakarta -> DKI Jakarta",
	    "Jawa Timur -> DKI Jakarta",
	    "DKI Jakarta -> Jawa Barat",
	    "Jawa -> Jawa",
	    "Jawa Barat -> DKI Jakarta",
	    "Sumatera Barat -> Sumatera Barat",
	    "DI Yogyakarta -> Jawa Timur",
	    "Jawa Tengah -> DKI Jakarta",
	    "Jawa Tengah -> DKI Jakarta",
	    "DKI Jakarta -> DKI Jakarta",
	    "Jawa Tengah -> DKI Jakarta",
	    "Jawa Timur -> Jawa Tengah",
	    "Jawa Barat -> Jawa Barat",
	    "Jawa -> Jawa Timur",
	    "Jawa Timur -> Jawa Timur",
	    "DKI Jakarta -> Jawa Timur",
	    "DI Yogyakarta -> Jawa Barat",
	    "Jawa Timur -> DKI Jakarta",
	    "Jawa Timur -> Jawa Barat",
	    "Jawa Timur -> Jawa Tengah",
	    "DKI Jakarta -> DKI Jakarta",
	    "Jawa Timur -> Jawa Barat",
	    "DKI Jakarta -> DKI Jakarta",
	    "Jawa Tengah -> Jawa Timur",
	    "Jawa Timur -> Jawa Timur",
	    "Sumatera Selatan -> Lampung",
	    "Sumatera Selatan -> Sumatera Selatan",
	    "Sumatera Selatan -> Lampung",
	    "Jawa Tengah -> Jawa Timur",
	    "Jawa Timur -> Jawa Barat",
	    "Jawa Barat -> DKI Jakarta",
	    "Jawa Barat -> Jawa Tengah",
	    "Jawa -> Jawa Barat",
	    "Jawa Barat -> Jawa Timur",
	    "Jawa Barat -> DKI Jakarta",
	    "Sumatera Barat -> Jawa Tengah",
	    "DI Yogyakarta -> DKI Jakarta",
	    "Jawa Tengah -> Jawa Tengah",
	    "Jawa Tengah -> DKI Jakarta",
	    "Jawa Tengah -> DKI Jakarta",
	    "DKI Jakarta -> DKI Jakarta",
	    "Jawa Tengah -> DKI Jakarta",
	    "DKI Jakarta -> Jawa Tengah",
	    "DKI Jakarta -> DKI Jakarta",
	    "Jawa Timur -> DKI Jakarta",
	    "Jawa Timur -> Jawa Timur",
	    "DKI Jakarta -> Jawa Barat",
	    "Jawa Tengah -> Jawa Timur",
	    "Jawa Barat -> DKI Jakarta",
	    "Jawa Tengah -> DKI Jakarta",
	    "DKI Jakarta -> DKI Jakarta",
	    "Jawa Tengah -> DKI Jakarta",
	    "DKI Jakarta -> DKI Jakarta",
	    "DKI Jakarta -> DKI Jakarta",
	    "Jawa Timur -> DKI Jakarta",
	    "Jawa Timur -> DKI Jakarta",
	    "DKI Jakarta -> DKI Jakarta",
	    "Jawa Timur -> DKI Jakarta",
	    "DKI Jakarta -> DKI Jakarta",
	    "DKI Jakarta -> DKI Jakarta",
	    "DKI Jakarta -> DKI Jakarta",
	    "DKI Jakarta -> DKI Jakarta",
	    "DKI Jakarta -> DKI Jakarta",
	    "DKI Jakarta -> DKI Jakarta",
	    "DKI Jakarta -> DKI Jakarta",
	    "DKI Jakarta -> DKI Jakarta",
	    "DKI Jakarta -> DKI Jakarta",
	    "DKI Jakarta -> DKI Jakarta",
	    "DKI Jakarta -> DKI Jakarta",
	};
	
	
	int hargaTiketJawa[100] = {
	    753978,
	    778598,
	    186292,
	    862143,
	    774707,
	    726811,
	    517354,
	    108946,
	    673579,
	    359072,
	    391370,
	    872898,
	    920215,
	    744946,
	    906457,
	    123288,
	    786356,
	    435179,
	    19255,
	    7787,
	    853040,
	    377868,
	    424608,
	    291421,
	    303852,
	    819183,
	    542658,
	    733089,
	    1145960,
	    200590,
	    438392,
	    378946,
	    263952,
	    818316,
	    445655,
	    695103,
	    205975,
	    356596,
	    516571,
	    161803,
	    985118,
	    330072,
	    358402,
	    364834,
	    187256,
	    368483,
	    799003,
	    719714,
	    255201,
	    260872,
	    985064,
	    887801,
	    1005409,
	    497754,
	    115986,
	    289284,
	    191274,
	    961225,
	    391140,
	    485249,
	    362144,
	    315484,
	    744589,
	    785880,
	    226085,
	    1147770,
	    206324,
	    113002,
	    331624,
	    10981,
	    24950,
	    373308,
	    203194,
	    5018,
	    626995,
	    341207,
	    668557,
	    214154,
	    1176218,
	    530712,
	    778229,
	    926849,
	    483670,
	    648591,
	    183907,
	    220326,
	    120186,
	    473369,
	    1005291,
	    425883,
	    836030,
	    350512,
	    270949,
	    429272,
	    140433,
	    101584,
	    330371,
	    1021133,
	    756063,
	    838476,
	};
	
	void tampilkanJadwalJawa(int index = 0) {
	    if (index == 100) return;
	
	    cout << index + 1 << ". | " << kodeKeretaJawa[index]
	         << " | " << stasiunAsalJawa[index]
	         << " -> " << stasiunTujuanJawa[index] << endl;
	    cout << "   Provinsi : " << ruteProvinsiJawa[index] << endl;
	    cout << "   Kereta   : " << namaKeretaJawa[index] << endl;
	    cout << "   Pukul    : " << jadwalKeretaJawa[index] << endl;
	    cout << "   Harga    : Rp " << hargaTiketJawa[index] << endl << endl;
	
	    tampilkanJadwalJawa(index + 1);
	}

	void cariNamaKeretaJawa(string nama) {
	    bool ditemukan = false;
	    cout << "\n=== HASIL PENCARIAN KERETA (JAWA) ===\n";
	
	    for (int i = 0; i < 100; i++) {
	        if (namaKeretaJawa[i].find(nama) != string::npos) {
	            ditemukan = true;
	            cout << i + 1 << ". | " << kodeKeretaJawa[i] << " | "
	                 << stasiunAsalJawa[i] << " -> " << stasiunTujuanJawa[i] << endl;
	            cout << "   Kereta   : " << namaKeretaJawa[i] << endl;
	            cout << "   Pukul    : " << jadwalKeretaJawa[i] << endl;
	            cout << "   Harga    : Rp " << hargaTiketJawa[i] << endl;
	            cout << "----------------------------------------\n";
	        }
	    }
	
	    if (!ditemukan)
	        cout << "Tidak ditemukan kereta dengan nama \"" << nama << "\".\n";
	}


};



//PENGUBAHAN CLASS KURSIKERETA MENJADI SINGLE LINKED LIST
class KursiKereta {
private:
    struct Node {
        string kodeKursi;
        bool terisi;
        bool prioritas;
        Node* next;    
    };

    Node* head;

public:
    KursiKereta() {
        head = NULL;
    }

    void tambahKursi() {
        string daftarKursi[10] = {
            "A1","A2","A3","A4","A5",
            "B1","B2","B3","B4","B5"
        };

        for (int i = 0; i < 10; i++) {
            Node* baru = new Node();
            baru->kodeKursi = daftarKursi[i];
            baru->next = NULL;

            if (daftarKursi[i] == "A2" || daftarKursi[i] == "B1" || daftarKursi[i] == "B4")
                baru->terisi = true;
            else
                baru->terisi = false;

            if (daftarKursi[i] == "A1" || daftarKursi[i] == "B5")
                baru->prioritas = true;
            else
                baru->prioritas = false;

            if (head == NULL) {
                head = baru;
            } else {
                Node* temp = head;
                while (temp->next != NULL) temp = temp->next;
                temp->next = baru;
            }
        }
    }

    void tampilkanKursi() {
        Node* temp = head;
        cout << "\nDaftar Kursi (Single Linked List):\n";
        while (temp != NULL) {
            cout << temp->kodeKursi << " - "
                 << (temp->terisi ? "Terisi" : "Kosong")
                 << (temp->prioritas ? " (Prioritas)" : "")
                 << endl;
            temp = temp->next;
        }
    }

    bool pesanKursi(string kode, bool isPrioritas = false) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->kodeKursi == kode) {
                if (temp->terisi) {
                    cout << "Kursi " << kode << " sudah terisi!\n";
                    return false;
                }
                if (temp->prioritas && !isPrioritas) {
                    cout << "Kursi " << kode << " adalah kursi prioritas!\n";
                    return false;
                }
                temp->terisi = true;
                cout << "Kursi " << kode << " berhasil dipesan!\n";
                return true;
            }
            temp = temp->next;
        }
        cout << "Kode kursi tidak ditemukan!\n";
        return false;
    }

    bool batalKursi(string kode) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->kodeKursi == kode) {
                temp->terisi = false;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool setKursiStatus(string kode, bool status) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->kodeKursi == kode) {
                temp->terisi = status;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void resetKursi() {
        Node* temp = head;
        while (temp != NULL) {
            temp->terisi = false;
            temp = temp->next;
        }
    }
};


//PENGUBAHAN CLASS PEMBAYARAN MENJADI SINGLE LINKED LIST
class pembayaran {
public:
    struct DataPembayaran {
        string namaPemesan;
        string metode;
        int total;
        int nomorKereta;
        int jumlahTiket;
        bool pulauJawa;

        DataPembayaran* next; 
    };

    DataPembayaran* head;
    DataPembayaran* tail;
    int jumlahPembayaran;

public:
    pembayaran() {
        head = NULL;
        tail = NULL;
        jumlahPembayaran = 0;
    }

    ~pembayaran() {
        DataPembayaran* temp = head;
        while (temp != NULL) {
            DataPembayaran* hapus = temp;
            temp = temp->next;
            delete hapus;
        }
    }

    void tambahPembayaran(string nama, string metode, int total, int nomorKereta, int jumlah, bool jawa) {
        DataPembayaran* baru = new DataPembayaran;
        baru->namaPemesan = nama;
        baru->metode = metode;
        baru->total = total;
        baru->nomorKereta = nomorKereta;
        baru->jumlahTiket = jumlah;
        baru->pulauJawa = jawa;
        baru->next = NULL;

        if (head == NULL) {   
            head = tail = baru;
        } else {
            tail->next = baru;
            tail = baru;
        }
        jumlahPembayaran++;
    }

    void prosesPembayaran(string nama, int total, int nomorKereta, int jumlah, bool jawa) {

        int pilih;
        string metode;
        cout << "\n===== PEMBAYARAN =====\n";
        cout << "1. Transfer Bank\n";
        cout << "2. E-Wallet\n";
        cout << "3. Tunai di Loket\n";
        cout << "Pilih metode: ";
        cin >> pilih;

        if (pilih == 1) { 
            int pilihBank;
            string bankName;
            cout << "\n=== TRANSFER BANK ===\n";
            cout << "Pilih Bank:\n";
            cout << "1. Mandiri\n";
            cout << "2. BRI\n";
            cout << "3. BCA\n";
            cout << "4. BPD\n";
            cout << "5. BNI\n";
            cout << "Pilihan bank: ";
            cin >> pilihBank;

            switch (pilihBank) {
                case 1: bankName = "Mandiri"; break;
                case 2: bankName = "BRI"; break;
                case 3: bankName = "BCA"; break;
                case 4: bankName = "BPD"; break;
                case 5: bankName = "BNI"; break;
                default: bankName = "Bank Lain"; break;
            }

            cout << "\nSilahkan transfer ke:\n";
            cout << bankName << " - No. Rekening: 1122334455 - a.n Kereta Indonesia\n";

            metode = "Transfer Bank - " + bankName;
        }
        else if (pilih == 2) {
            int pilihEW;
            string ewName;
            cout << "\n=== E-WALLET ===\n";
            cout << "Pilih E-Wallet:\n";
            cout << "1. DANA\n";
            cout << "2. GoPay\n";
            cout << "3. ShopeePay\n";
            cout << "4. OVO\n";
            cout << "Pilihan: ";
            cin >> pilihEW;

            switch (pilihEW) {
                case 1: ewName = "DANA"; break;
                case 2: ewName = "GoPay"; break;
                case 3: ewName = "ShopeePay"; break;
                case 4: ewName = "OVO"; break;
                default: ewName = "E-Wallet Lain"; break;
            }

            metode = "E-Wallet - " + ewName;
        }
        else if (pilih == 3) { 
            metode = "Tunai di Loket";
        }
        else {
            metode = "Lainnya";
        }

        cout << "Pembayaran sebesar Rp " << total << " dicatat dengan metode: " << metode << "!\n";
        tambahPembayaran(nama, metode, total, nomorKereta, jumlah, jawa);
    }

    void tampilkanRiwayat() {
        cout << "\n===== RIWAYAT PEMBAYARAN =====\n";
        if (jumlahPembayaran == 0) {
            cout << "Belum ada transaksi pembayaran.\n";
            return;
        }

        DataPembayaran* temp = head;
        int i = 1;
        while (temp != NULL) {
            cout << i++ << ". Nama: " << temp->namaPemesan;
            cout << " | Metode: " << temp->metode;
            cout << " | Total: Rp " << temp->total << endl;
            temp = temp->next;
        }
    }

    DataPembayaran getDataPembayaran(int index) {
        DataPembayaran* temp = head;
        int i = 0;

        while (temp != NULL) {
            if (i == index) return *temp;
            temp = temp->next;
            i++;
        }

        return DataPembayaran(); 
    }

    DataPembayaran removeLastPayment() {
        DataPembayaran empty;

        if (head == NULL) return empty;

        if (head == tail) {  
            DataPembayaran last = *head;
            delete head;
            head = tail = NULL;
            jumlahPembayaran = 0;
            return last;
        }

        DataPembayaran* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }

        DataPembayaran last = *tail;
        delete tail;
        tail = temp;
        tail->next = NULL;
        jumlahPembayaran--;

        return last;
    }

    void editPembayaran(jadwalKereta &data) {

        if (jumlahPembayaran == 0) {
            cout << "\nBelum ada pembayaran yang bisa diedit!\n";
            return;
        }

        tampilkanRiwayat();
        int pilihEdit;
        cout << "\nPilih nomor pesanan yang ingin diedit: ";
        cin >> pilihEdit;

        if (pilihEdit < 1 || pilihEdit > jumlahPembayaran) {
            cout << "Pilihan tidak valid!\n";
            return;
        }

        int nomor = pilihEdit - 1;
        DataPembayaran* temp = head;

        for (int i = 0; i < nomor; i++) {
            temp = temp->next;
        }

        int nomorKereta, tiketBaru;
        cout << "\nMasukkan nomor kereta baru (1-20): ";
        cin >> nomorKereta;

        if (nomorKereta < 1 || nomorKereta > 20) {
            cout << "Nomor kereta tidak valid!\n";
            return;
        }

        cout << "Masukkan jumlah tiket baru: ";
        cin >> tiketBaru;

        int hargaBaru = tiketBaru * data.hargaTiket[nomorKereta - 1];

        temp->total = hargaBaru;
        temp->jumlahTiket = tiketBaru;
        temp->nomorKereta = nomorKereta;

        cout << "\nPesanan berhasil diedit!\n";
        cout << "Nama Pemesan : " << temp->namaPemesan << endl;
        cout << "Kereta Baru  : " << data.namaKereta[nomorKereta - 1] << endl;
        cout << "Total Baru   : Rp " << hargaBaru << endl;
    }
};




// materi 6 stack dengan array undo/redo 
struct Booking {
    string namaPemesan;
    int nomorKereta;
    int jumlahTiket;
    bool pulauJawa;
    string kursiCodes[10];
    int kursiCount;
    pembayaran::DataPembayaran paymentData;

    DataKTP ktp;   
};



Booking undoStack[100];
Booking redoStack[100];
int topUndo = -1;
int topRedo = -1;


void pushUndoBooking(const Booking &b) { if (topUndo < 99) undoStack[++topUndo] = b; }
void pushRedoBooking(const Booking &b) { if (topRedo < 99) redoStack[++topRedo] = b; }
Booking popUndoBooking() { return undoStack[topUndo--]; }
Booking popRedoBooking() { return redoStack[topRedo--]; }
bool isUndoEmpty(){ return topUndo == -1; }
bool isRedoEmpty(){ return topRedo == -1; }


class AntrianPemesanan {
private:
    struct Node {
        Booking data;
        Node* next;
    };

    Node* head;
    Node* tail;

public:
    AntrianPemesanan() {
        head = tail = NULL;
    }

    void enqueue(Booking b) {
        Node* baru = new Node{b, NULL};
        if (!head) head = tail = baru;
        else {
            tail->next = baru;
            tail = baru;
        }
    }

    bool dequeue() {
        if (!head) return false;
        Node* hapus = head;
        head = head->next;
        if (!head) tail = NULL;
        delete hapus;
        return true;
    }
};


class pemesananTiket {
private:
    string namaPemesan;
    int pilihanKereta;
    int jumlahTiket;
    int totalHarga;
    bool sudahDipesan = false;

public:


    void inputData() {
        cout << "\nMasukkan nama pemesan : ";
        cin.ignore();
        getline(cin, namaPemesan);
    }

    
   	void pesan(jadwalKereta &data, pembayaran &bayar, KursiKereta kursiSumatra[]) {

        cout << "\n========== PEMESANAN TIKET ==========\n";
		DataKTP dataKTP;
		inputKTP(dataKTP);   // ? KTP DI SINI
		inputData();


        cout << "Masukkan nomor kereta yang ingin dipesan (1-20): ";
        cin >> pilihanKereta;

        if (pilihanKereta < 1 || pilihanKereta > 20) {
            cout << "Nomor kereta tidak valid!\n";
            return;
        }

      

        cout << "Masukkan jumlah tiket yang ingin dibeli : ";
        cin >> jumlahTiket;
        
        cout << "\nPilih kursi untuk setiap tiket:\n";

        Booking b;
        b.namaPemesan = namaPemesan;
        b.ktp = dataKTP;
        b.nomorKereta = pilihanKereta;
        b.jumlahTiket = jumlahTiket;
        b.pulauJawa = false;
        b.kursiCount = 0;
        


		for (int i = 1; i <= jumlahTiket; i++) {
		    string kode;
		    cout << "\nKursi ke-" << i << " untuk KA" << data.kodeKereta[pilihanKereta - 1] << ":\n";
		    
		    
		    kursiSumatra[pilihanKereta - 1].tampilkanKursi();


		    cout << "Masukkan kode kursi: ";
		    cin >> kode;
		
		    while (!kursiSumatra[pilihanKereta - 1].pesanKursi(kode)) {
		        cout << "Masukkan kode kursi lain: ";
		        cin >> kode;
		    }

		    if (b.kursiCount < 10) {
		        b.kursiCodes[b.kursiCount++] = kode;
		    }
		}


        totalHarga = jumlahTiket * data.hargaTiket[pilihanKereta - 1];
        cetakStruk(data);
        
        bayar.prosesPembayaran(namaPemesan, totalHarga, pilihanKereta, jumlahTiket, false);

        if (bayar.jumlahPembayaran > 0) {
            b.paymentData = bayar.getDataPembayaran(bayar.jumlahPembayaran - 1);
        } else {
            
            b.paymentData.namaPemesan = namaPemesan;
            b.paymentData.total = totalHarga;
            b.paymentData.nomorKereta = pilihanKereta;
            b.paymentData.jumlahTiket = jumlahTiket;
            b.paymentData.pulauJawa = false;
            b.paymentData.metode = "Unknown";
        }

       	//stack
        pushUndoBooking(b);
        topRedo = -1;

        sudahDipesan = true;

    }

    
    void cetakStruk(jadwalKereta &data) {
        cout << "\n=========================================\n";
        cout << "             STRUK PEMESANAN             \n";
        cout << "=========================================\n";
        cout << "Nama Pemesan : " << namaPemesan << endl;
        cout << "Kode Kereta  : " << data.kodeKereta[pilihanKereta - 1] << endl;
        cout << "Nama Kereta  : " << data.namaKereta[pilihanKereta - 1] << endl;
        cout << "Asal         : " << data.stasiunAsal[pilihanKereta - 1] << endl;
        cout << "Tujuan       : " << data.stasiunTujuan[pilihanKereta - 1] << endl;
        cout << "Jadwal       : " << data.jadwalKereta[pilihanKereta - 1] << endl;
        cout << "Jumlah Tiket : " << jumlahTiket << endl;
        cout << "Total Bayar  : Rp " << totalHarga << endl;
        cout << "=========================================\n";
        cout << "Tiket berhasil dipesan! Selamat perjalanan!\n";
        cout << "=========================================\n";
    }
    
    void pesanJawa(jadwalKeretaJawa &data, pembayaran &bayar, KursiKereta kursiJawa[]) {
	   cout << "\n========== PEMESANAN TIKET ==========\n";
	   DataKTP dataKTP;
	   inputKTP(dataKTP);   // ? KTP DI SINI
	   inputData();

	    cout << "Masukkan nomor kereta yang ingin dipesan (1-100): ";
	    cin >> pilihanKereta;
	
	    if (pilihanKereta < 1 || pilihanKereta > 100) {
	        cout << "Nomor kereta tidak valid!\n";
	        return;
	    }
	
	    cout << "Masukkan jumlah tiket : ";
	    cin >> jumlahTiket;
	    
	    cout << "\nPilih kursi untuk setiap tiket:\n";

        Booking b;
        b.namaPemesan = namaPemesan;
        b.ktp = dataKTP;
        b.nomorKereta = pilihanKereta;
        b.jumlahTiket = jumlahTiket;
        b.pulauJawa = true;
        b.kursiCount = 0;

		for (int i = 1; i <= jumlahTiket; i++) {
		    string kode;
		    cout << "\nKursi ke-" << i << " untuk KA" << data.kodeKeretaJawa[pilihanKereta - 1] << ":\n";
		    
		    
		    kursiJawa[pilihanKereta - 1].tampilkanKursi();

		    cout << "Masukkan kode kursi: ";
		    cin >> kode;

		    while (!kursiJawa[pilihanKereta - 1].pesanKursi(kode)) {
		        cout << "Masukkan kode kursi lain: ";
		        cin >> kode;
		    }

		    if (b.kursiCount < 10) {
		        b.kursiCodes[b.kursiCount++] = kode;
		    }
		}

	
	    totalHarga = jumlahTiket * data.hargaTiketJawa[pilihanKereta - 1];
	
	    cout << "\n========== STRUK PEMESANAN JAWA ==========\n";
	    cout << "Nama Pemesan : " << namaPemesan << endl;
	    cout << "Kode Kereta  : " << data.kodeKeretaJawa[pilihanKereta - 1] << endl;
	    cout << "Nama Kereta  : " << data.namaKeretaJawa[pilihanKereta - 1] << endl;
	    cout << "Asal         : " << data.stasiunAsalJawa[pilihanKereta - 1] << endl;
	    cout << "Tujuan       : " << data.stasiunTujuanJawa[pilihanKereta - 1] << endl;
	    cout << "Jadwal       : " << data.jadwalKeretaJawa[pilihanKereta - 1] << endl;
	    cout << "Jumlah Tiket : " << jumlahTiket << endl;
	    cout << "Total Bayar  : Rp " << totalHarga << endl;
	    cout << "=========================================\n";
	    cout << "Tiket berhasil dipesan! Selamat perjalanan!\n";
	    cout << "=========================================\n";
	
	    bayar.prosesPembayaran(namaPemesan, totalHarga, pilihanKereta, jumlahTiket, true);

        if (bayar.jumlahPembayaran > 0) {
            b.paymentData = bayar.getDataPembayaran(bayar.jumlahPembayaran - 1);
        } else {
            b.paymentData.namaPemesan = namaPemesan;
            b.paymentData.total = totalHarga;
            b.paymentData.nomorKereta = pilihanKereta;
            b.paymentData.jumlahTiket = jumlahTiket;
            b.paymentData.pulauJawa = true;
            b.paymentData.metode = "Unknown";
        }

        pushUndoBooking(b);
        topRedo = -1;

	    sudahDipesan = true;

	}
	
	void cetakTiket(jadwalKereta &sum, jadwalKeretaJawa &jawa, pembayaran::DataPembayaran data,Booking b){
	
	    int idx = data.nomorKereta - 1;
	
	    cout << "\n=========== CETAK TIKET ===========" << endl;
	    cout << "Nama Pemesan : " << data.namaPemesan << endl;
		cout << "Nama (KTP) : " << b.ktp.nama << endl;
		cout << "NIK        : " << b.ktp.nik << endl;

	    if (!data.pulauJawa) {
	        cout << "Kode Kereta  : " << sum.kodeKereta[idx] << endl;
	        cout << "Nama Kereta  : " << sum.namaKereta[idx] << endl;
	        cout << "Asal         : " << sum.stasiunAsal[idx] << endl;
	        cout << "Tujuan       : " << sum.stasiunTujuan[idx] << endl;
	        cout << "Jadwal       : " << sum.jadwalKereta[idx] << endl;
	    } else {
	        cout << "Kode Kereta  : " << jawa.kodeKeretaJawa[idx] << endl;
	        cout << "Nama Kereta  : " << jawa.namaKeretaJawa[idx] << endl;
	        cout << "Asal         : " << jawa.stasiunAsalJawa[idx] << endl;
	        cout << "Tujuan       : " << jawa.stasiunTujuanJawa[idx] << endl;
	        cout << "Jadwal       : " << jawa.jadwalKeretaJawa[idx] << endl;
	    }
	
	    cout << "Jumlah Tiket : " << data.jumlahTiket << endl;
	    cout << "Total Bayar  : Rp " << data.total << endl;
	    cout << "===================================" << endl;
	    cout << "Selamat menikmati perjalanan!" << endl;
	    cout << "===================================" << endl;
	}
	
	int binarySearchProvinsi(string arr[], int size, string key) {
	    int left = 0, right = size - 1;
	    while (left <= right) {
	        int mid = (left + right) / 2;
	        if (arr[mid] == key)
	            return mid;
	        else if (arr[mid] < key)
	            left = mid + 1;
	        else
	            right = mid - 1;
	    }
	    return -1;
	}
	
	void cariProvinsiSumatra(jadwalKereta &data) {
	    string provinsi;
	    cout << "\nMasukkan Provinsi (contoh: Aceh): ";
	    cin.ignore();
	    getline(cin, provinsi);
	
	    bool ditemukan = false;
	
	    cout << "\n===== HASIL PENCARIAN KERETA PROVINSI: " << provinsi << " =====\n";
	
	    for (int i = 0; i < 20; i++) {
	        if (data.ruteProvinsi[i].find(provinsi) != string::npos) {
			    cout << (i + 1) << ". "
			         << data.kodeKereta[i] << " | "
			         << data.namaKereta[i] << " | "
			         << data.stasiunAsal[i] << " -> "
			         << data.stasiunTujuan[i] << endl;
			    ditemukan = true;
			}

	    }
	
	    if (!ditemukan) {
	        cout << "Tidak ada rute sesuai provinsi tersebut.\n";
	    }
	}


	void cariProvinsiJawa(jadwalKeretaJawa &data) {
	    string provinsi;
	    cout << "\nMasukkan Provinsi (contoh: Jawa Barat): ";
	    cin.ignore();
	    getline(cin, provinsi);
	
	    bool ditemukan = false;
	
	    cout << "\n===== HASIL PENCARIAN KERETA PROVINSI: " << provinsi << " =====\n";
	
	    for (int i = 0; i < 100; i++) {
	        if (data.ruteProvinsiJawa[i].find(provinsi) != string::npos) {
			    cout << (i + 1) << ". "
			         << data.kodeKeretaJawa[i] << " | "
			         << data.namaKeretaJawa[i] << " | "
			         << data.stasiunAsalJawa[i] << " -> "
			         << data.stasiunTujuanJawa[i] << endl;
			    ditemukan = true;
			}

	    }
	
	    if (!ditemukan) {
	        cout << "Tidak ada rute sesuai provinsi tersebut.\n";
	    }
	}

	void cariKodeSumatra(jadwalKereta &data) {
	    string kode;
	    cout << "\nMasukkan Kode Kereta (contoh: KA001): ";
	    cin.ignore();
	    getline(cin, kode);
	
	    bool ditemukan = false;
	    cout << "\n===== HASIL PENCARIAN KERETA KODE: " << kode << " =====\n";
	
	    for (int i = 0; i < 20; i++) {
	        if (data.kodeKereta[i] == kode) { 
	            cout << (i + 1) << ". "
	                 << data.kodeKereta[i] << " | "
	                 << data.namaKereta[i] << " | "
	                 << data.stasiunAsal[i] << " -> "
	                 << data.stasiunTujuan[i] << endl;
	            cout << "   Provinsi : " << data.ruteProvinsi[i] << endl;
	            cout << "   Pukul    : " << data.jadwalKereta[i] << endl;
	            cout << "   Harga    : Rp " << data.hargaTiket[i] << endl;
	            ditemukan = true;
	            break; 
	        }
	    }
	
	    if (!ditemukan) {
	        cout << "Kode kereta " << kode << " tidak ditemukan.\n";
	    }
	}
	
	void cariKodeJawa(jadwalKeretaJawa &data) {
	    string kode;
	    cout << "\nMasukkan Kode Kereta (contoh: KA-JKS-SLO): ";
	    cin.ignore();
	    getline(cin, kode);
	
	    bool ditemukan = false;
	    cout << "\n===== HASIL PENCARIAN KERETA KODE: " << kode << " =====\n";
	
	    for (int i = 0; i < 100; i++) {
	        if (data.kodeKeretaJawa[i] == kode) {
	            cout << (i + 1) << ". "
	                 << data.kodeKeretaJawa[i] << " | "
	                 << data.namaKeretaJawa[i] << " | "
	                 << data.stasiunAsalJawa[i] << " -> "
	                 << data.stasiunTujuanJawa[i] << endl;
	            cout << "   Provinsi : " << data.ruteProvinsiJawa[i] << endl;
	            cout << "   Pukul    : " << data.jadwalKeretaJawa[i] << endl;
	            cout << "   Harga    : Rp " << data.hargaTiketJawa[i] << endl;
	            ditemukan = true;
	            break;
	        }
	    }
	
	    if (!ditemukan) {
	        cout << "Kode kereta " << kode << " tidak ditemukan.\n";
	    }
	}
	
	//menambahkan fitur cetak tiket di file txt
	void simpanTiketTXT(jadwalKereta &sum, jadwalKeretaJawa &jawa, pembayaran::DataPembayaran data) {
	    int idx = data.nomorKereta - 1;
	
	    string fileName = "Tiket-" + data.namaPemesan + "-" + (data.pulauJawa ? jawa.kodeKeretaJawa[idx] : sum.kodeKereta[idx]) + ".txt";
	
	    ofstream file(fileName.c_str());
	
	    if (!file) {
	        cout << "Gagal membuat file tiket!\n";
	        return;
	    }
	
	    file << "=====================================\n";
	    file << "            TIKET KERETA             \n";
	    file << "=====================================\n";
	    file << "Nama Pemesan : " << data.namaPemesan << endl;
	
	    if (!data.pulauJawa) {
	        file << "Kode Kereta  : " << sum.kodeKereta[idx] << endl;
	        file << "Nama Kereta  : " << sum.namaKereta[idx] << endl;
	        file << "Asal         : " << sum.stasiunAsal[idx] << endl;
	        file << "Tujuan       : " << sum.stasiunTujuan[idx] << endl;
	        file << "Jadwal       : " << sum.jadwalKereta[idx] << endl;
	    } else {
	        file << "Kode Kereta  : " << jawa.kodeKeretaJawa[idx] << endl;
	        file << "Nama Kereta  : " << jawa.namaKeretaJawa[idx] << endl;
	        file << "Asal         : " << jawa.stasiunAsalJawa[idx] << endl;
	        file << "Tujuan       : " << jawa.stasiunTujuanJawa[idx] << endl;
	        file << "Jadwal       : " << jawa.jadwalKeretaJawa[idx] << endl;
	    }
	
	    file << "Jumlah Tiket : " << data.jumlahTiket << endl;
	    file << "Total Bayar  : Rp " << data.total << endl;
	    file << "=====================================\n";
	    file << "Selamat menikmati perjalanan!\n";
	    file << "=====================================\n";
	
	    file.close();
	
	    cout << "Tiket berhasil disimpan ke file: " << fileName << endl;
	}
	

};



// PENGUBAHAN CLASSS UNDOREDO MENJADI SINGLE LINKED LIST
class UndoRedoBooking {
public:

    struct NodeBooking {
        Booking data;
        NodeBooking* next;
    };

    NodeBooking* undoHead;
    NodeBooking* undoTail;

    NodeBooking* redoHead;
    NodeBooking* redoTail;

public:

    UndoRedoBooking() {
        undoHead = undoTail = NULL;
        redoHead = redoTail = NULL;
    }

    ~UndoRedoBooking() {

        NodeBooking* temp = undoHead;
        while (temp != NULL) {
            NodeBooking* del = temp;
            temp = temp->next;
            delete del;
        }

        temp = redoHead;
        while (temp != NULL) {
            NodeBooking* del = temp;
            temp = temp->next;
            delete del;
        }
    }

    bool isUndoEmpty() { return undoHead == NULL; }
    bool isRedoEmpty() { return redoHead == NULL; }

    void pushUndoBooking(Booking b) {
        NodeBooking* baru = new NodeBooking;
        baru->data = b;
        baru->next = NULL;

        if (undoHead == NULL) {
            undoHead = undoTail = baru;
        } else {
            undoTail->next = baru;
            undoTail = baru;
        }
    }

    Booking popUndoBooking() {
        Booking dummy;

        if (undoHead == NULL) return dummy;

        if (undoHead == undoTail) {
            Booking b = undoHead->data;
            delete undoHead;
            undoHead = undoTail = NULL;
            return b;
        }

        NodeBooking* temp = undoHead;
        while (temp->next != undoTail) {
            temp = temp->next;
        }

        Booking b = undoTail->data;
        delete undoTail;

        undoTail = temp;
        undoTail->next = NULL;

        return b;
    }

    void pushRedoBooking(Booking b) {
        NodeBooking* baru = new NodeBooking;
        baru->data = b;
        baru->next = NULL;

        if (redoHead == NULL) {
            redoHead = redoTail = baru;
        } else {
            redoTail->next = baru;
            redoTail = baru;
        }
    }

    Booking popRedoBooking() {
        Booking dummy;

        if (redoHead == NULL) return dummy;

        if (redoHead == redoTail) {
            Booking b = redoHead->data;
            delete redoHead;
            redoHead = redoTail = NULL;
            return b;
        }

        NodeBooking* temp = redoHead;
        while (temp->next != redoTail) {
            temp = temp->next;
        }

        Booking b = redoTail->data;
        delete redoTail;

        redoTail = temp;
        redoTail->next = NULL;

        return b;
    }
    
    void undoBooking(KursiKereta kursiSumatra[], KursiKereta kursiJawa[], pembayaran &bayar) {
	    if (isUndoEmpty()) {
	        cout << "\nTidak ada pemesanan yang bisa di-undo!\n";
	        return;
	    }
	
	    Booking last = popUndoBooking();
	
	    if (!last.pulauJawa) {
	        for (int i = 0; i < last.kursiCount; i++) {
	            kursiSumatra[last.nomorKereta - 1].batalKursi(last.kursiCodes[i]);
	        }
	    } else {
	        for (int i = 0; i < last.kursiCount; i++) {
	            kursiJawa[last.nomorKereta - 1].batalKursi(last.kursiCodes[i]);
	        }
	    }
	
	    bayar.removeLastPayment();
	    pushRedoBooking(last);
	
	    cout << "\nUNDO berhasil! Pemesanan terakhir dibatalkan.\n";
	}
	
	void redoBooking(KursiKereta kursiSumatra[], KursiKereta kursiJawa[], pembayaran &bayar) {
	    if (isRedoEmpty()) {
	        cout << "\nTidak ada pemesanan yang bisa di-redo!\n";
	        return;
	    }
	
	    Booking last = popRedoBooking();
	
	    if (!last.pulauJawa) {
	        for (int i = 0; i < last.kursiCount; i++) {
	            kursiSumatra[last.nomorKereta - 1].setKursiStatus(last.kursiCodes[i], true);
	        }
	    } else {
	        for (int i = 0; i < last.kursiCount; i++) {
	            kursiJawa[last.nomorKereta - 1].setKursiStatus(last.kursiCodes[i], true);
	        }
	    }
	
	    bayar.tambahPembayaran(
	        last.namaPemesan,
	        last.paymentData.metode,
	        last.paymentData.total,
	        last.paymentData.nomorKereta,
	        last.paymentData.jumlahTiket,
	        last.paymentData.pulauJawa
	    );
	
	    pushUndoBooking(last);
	
	    cout << "\nREDO berhasil! Pemesanan dikembalikan.\n";
	}

};

void undoBooking(KursiKereta kursiSumatra[], KursiKereta kursiJawa[], pembayaran &bayar);
void redoBooking(KursiKereta kursiSumatra[], KursiKereta kursiJawa[], pembayaran &bayar);



int main() {
    jadwalKereta data;
    pemesananTiket pesan;
    pembayaran bayar;
    jadwalKeretaJawa jawa;
    jadwalKereta jadwal;          
    jadwalKeretaJawa jadwalJawa;  
    
    KursiKereta kursiSumatra[20];
	KursiKereta kursiJawa[100];
	int pilihPulau = 0;
	
	for (int i = 0; i < 20; i++) {
	    kursiSumatra[i].tambahKursi();
	}
	for (int i = 0; i < 100; i++) {
	    kursiJawa[i].tambahKursi();
	}

	
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << "|                                                                                             |" << endl;
	cout << "|                                                                                             |" << endl;
	cout << "|             S   I   S   T   E   M          K   A   I          A   K   S   E   S             |" << endl;
	cout << "|                                                                                             |" << endl;
	cout << "|                                                                                             |" << endl;
	cout << "|                                                                                             |" << endl;
	cout << "|                                 B   Y       P  .  T                                         |" << endl;
	cout << "|                                                                                             |" << endl;
	cout << "|                                                                                             |" << endl;
	cout << "|                                                                                             |" << endl;
	cout << "|     K   E   R   E   T   A          A   P   I          I   N   D   O   N   E   S   I   A     |" << endl;
	cout << "|                                                                                             |" << endl;
	cout << "|                                                                                             |" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	
	system("pause"); 
    system("cls");
	
    int menu;
	int masuk = 0;
	
	while (1) {
	    printf("\n===== LOGIN / BUAT AKUN =====\n");
	    printf("1. Registrasi Akun\n");
	    printf("2. Login\n");
	    printf("3. Logout\n");
	    printf("Pilih: ");
	    scanf("%d", &menu);
	
	    if (menu == 1) {
	        registrasi();     
	    }
	    else if (menu == 2) {
	        masuk = login(); 
            if (masuk) {
			    int pilihPulau;
			    cout << "\n===== LOKASI PULAU =====\n";
			    cout << "1. Pulau Sumatra\n";
			    cout << "2. Pulau Jawa\n";
			    cout << "Pilih: ";
			    cin >> pilihPulau;
			    system("cls");

                int pilih;
                do {
                    cout << "\n===== MENU LAYANAN KAI AKSES =====\n";
                    cout << "1. Lihat Jadwal Kereta\n";
                    cout << "2. Pesan Tiket + Pembayaran\n";
                    cout << "3. Lihat Riwayat Pembayaran\n";
					cout << "4. Edit Pesanan\n";
					cout << "5. Cetak Tiket\n";
					cout << "6. Cari Berdasarkan Provinsi Rute Kereta\n";
					cout << "7. Cari Berdasarkan Kode Kereta\n";
					cout << "8. Cari Berdasarkan Nama Kereta\n";
					cout << "9. Undo Pembatalan Pemesanan Terakhir\n";
                    cout << "10. Redo Pembatalan Pemesanan Terakhir\n";
                    cout << "11. Logout\n";
                    cout << "Pilih: ";
                    cin >> pilih;

                    switch (pilih) {
			            case 1:
			                if (pilihPulau == 1) data.tampilkanJadwal(0);
			                else jawa.tampilkanJadwalJawa(0);
			                system("pause"); 
                			system("cls");
			                break;
			
			            case 2:
			                if (pilihPulau == 1) {
			                    data.tampilkanJadwal(0);
			                    pesan.pesan(data, bayar, kursiSumatra);

			                } else {
			                    jawa.tampilkanJadwalJawa(0);
			                    pesan.pesanJawa(jawa, bayar, kursiJawa);
			                }
			                system("pause"); 
                			system("cls");
			                break;
                        case 3: 
							bayar.tampilkanRiwayat(); 
							system("pause"); 
                			system("cls");
							break;
                        case 4:
						    bayar.editPembayaran(data);
						    system("pause"); 
                			system("cls");
						    break;
						case 5:
						    cout << "\n===== CETAK SEMUA TIKET =====\n";
						    for (int i = 0; i < bayar.jumlahPembayaran; i++) {
						        pesan.cetakTiket(data, jawa, bayar.getDataPembayaran(i), undoStack[i]  ); 
						        pesan.simpanTiketTXT(data, jawa, bayar.getDataPembayaran(i)); // <-- tambahan
						    }
						    system("pause");
						    system("cls");
						    break;

						case 6:
						    if (pilihPulau == 1){
						    	pesan.cariProvinsiSumatra(data);
							} 
						    else {
						    	pesan.cariProvinsiJawa(jawa);
							}
							system("pause"); 
                			system("cls");
						    break;
						case 7:
							    int sub_pilih;
							    cout << "\n===== CARI JADWAL BERDASARKAN =====" << endl;
							    cout << "1. Provinsi Rute" << endl;
							    cout << "2. Kode Kereta " << endl;
							    cout << "Pilih: ";
							    if (!(cin >> sub_pilih)) {
							        cin.clear(); cin.ignore(10000, '\n');
							        cout << "Input tidak valid!\n";
							        break;
							    }
							    
							    if (sub_pilih == 1) {
							        if (pilihPulau == 1){
							            pesan.cariProvinsiSumatra(data);
							        } 
							        else {
							            pesan.cariProvinsiJawa(jawa);
							        }
							    } else if (sub_pilih == 2) {
							        if (pilihPulau == 1) {
							            pesan.cariKodeSumatra(data);
							        } else {
							            pesan.cariKodeJawa(jawa);
							        }
							    } else {
							        cout << "Pilihan sub-menu tidak valid!\n";
							    }
							    
							    system("pause"); 
							    system("cls");
							    break;
						case 8: {
						    string nama;
						    cout << "Masukkan nama kereta yang dicari: ";
						    cin.ignore();
						    getline(cin, nama);
						
						    if (pilihPulau == 1) {
						        
						        jadwal.cariNamaKereta(nama);  
						    }
						    else if (pilihPulau == 2) {
						        
						        jadwalJawa.cariNamaKeretaJawa(nama);
						    }
						    else {
						        cout << "Anda belum memilih pulau!\n";
						    }
						}
						break;

                        case 9:
                            undoBooking(kursiSumatra, kursiJawa, bayar);
                            system("pause");
                            system("cls");
                            break;
                        case 10:
                            redoBooking(kursiSumatra, kursiJawa, bayar);
                            system("pause");
                            system("cls");
                            break;
						
						case 11:
						    cout << "Logout Berhasil!";
						    break;

                        default: 
							cout << "Pilihan tidak valid!\n"; 
							break;
						
                    }
                } while (pilih != 11);
            }
        } else if (menu == 3) {
            cout << "-----------------------------------------------------------------------------------------------" << endl;
			cout << "|                                                                                             |" << endl;
			cout << "|                                                                                             |" << endl;
			cout << "|        A   N   D   A          T   E   L   A   H          L   O   G   O   U   T   !          |" << endl;
			cout << "|                                                                                             |" << endl;
			cout << "|                                                                                             |" << endl;
			cout << "|                                                                                             |" << endl;
			cout << "|             S   I   S   T   E   M          K   A   I          A   K   S   E   S             |" << endl;
			cout << "|                                                                                             |" << endl;
			cout << "|                                                                                             |" << endl;
			cout << "|                                                                                             |" << endl;
			cout << "|                                 B   Y       P  .  T                                         |" << endl;
			cout << "|                                                                                             |" << endl;
			cout << "|                                                                                             |" << endl;
			cout << "|                                                                                             |" << endl;
			cout << "|     K   E   R   E   T   A          A   P   I          I   N   D   O   N   E   S   I   A     |" << endl;
			cout << "|                                                                                             |" << endl;
			cout << "|                                                                                             |" << endl;
			cout << "-----------------------------------------------------------------------------------------------" << endl;
            break;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}

void undoBooking(KursiKereta kursiSumatra[], KursiKereta kursiJawa[], pembayaran &bayar) {
    if (isUndoEmpty()) {
        cout << "\nTidak ada pemesanan yang bisa di-undo!\n";
        return;
    }

    Booking b = popUndoBooking();

    if (!b.pulauJawa) {
        for (int i = 0; i < b.kursiCount; i++) {
            kursiSumatra[b.nomorKereta - 1].batalKursi(b.kursiCodes[i]);
        }
    } else {
        for (int i = 0; i < b.kursiCount; i++) {
            kursiJawa[b.nomorKereta - 1].batalKursi(b.kursiCodes[i]);
        }
    }

    bayar.removeLastPayment();

    pushRedoBooking(b);

    cout << "\nUNDO berhasil! Pemesanan dibatalkan.\n";
}

void redoBooking(KursiKereta kursiSumatra[], KursiKereta kursiJawa[], pembayaran &bayar) {
    if (isRedoEmpty()) {
        cout << "\nTidak ada pemesanan yang bisa di-redo!\n";
        return;
    }

    Booking b = popRedoBooking();

    if (!b.pulauJawa) {
        for (int i = 0; i < b.kursiCount; i++) {
            kursiSumatra[b.nomorKereta - 1].setKursiStatus(b.kursiCodes[i], true);
        }
    } else {
        for (int i = 0; i < b.kursiCount; i++) {
            kursiJawa[b.nomorKereta - 1].setKursiStatus(b.kursiCodes[i], true);
        }
    }

    bayar.tambahPembayaran(
        b.paymentData.namaPemesan,
        b.paymentData.metode,
        b.paymentData.total,
        b.paymentData.nomorKereta,
        b.paymentData.jumlahTiket,
        b.paymentData.pulauJawa
    );

    pushUndoBooking(b);

    cout << "\nREDO berhasil! Pemesanan dikembalikan.\n";
}

