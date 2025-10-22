// Class Produk
class Produk {
    private String kodeProduk;
    private String namaProduk;
    private double harga;

    // Constructor default
    public Produk() {
        kodeProduk = "P000";
        namaProduk = "Unknown";
        harga = 0;
    }

    // Constructor berparameter
    public Produk(String kode, String nama, double harga) {
        this.kodeProduk = kode;
        this.namaProduk = nama;
        this.harga = harga;
    }

    // Getter
    public String getKodeProduk() { return kodeProduk; }
    public String getNamaProduk() { return namaProduk; }
    public double getHarga() { return harga; }

    // Setter
    public void setKodeProduk(String kode) { this.kodeProduk = kode; }
    public void setNamaProduk(String nama) { this.namaProduk = nama; }

    public void setHarga(double harga) {
        if (harga > 0) {
            this.harga = harga;
        } else {
            System.out.println("Harga tidak valid! Harus lebih besar dari 0.");
        }
    }

    // Tampilkan info produk
    public void tampilkanInfo() {
        System.out.println("\n=== Data Produk ===");
        System.out.println("Kode Produk : " + kodeProduk);
        System.out.println("Nama Produk : " + namaProduk);
        System.out.println("Harga       : Rp " + harga);
    }
}

// Class Tester
public class Tester {
    public static void main(String[] args) {
        Produk p1 = new Produk();
        Produk p2 = new Produk("P001", "Rendang Padang", 75000);

        p1.tampilkanInfo();
        p2.tampilkanInfo();

        System.out.println("\n--- Uji setter harga ---");
        p1.setHarga(-5000);
        p1.setHarga(25000);

        p1.tampilkanInfo();
    }
}
