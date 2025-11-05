// Superclass
class Pembayaran {
    public void proses(double total) {
        System.out.println("Memproses pembayaran sebesar: Rp " + total);
    }
}

// Subclass 1: Tunai
class Tunai extends Pembayaran {
    @Override
    public void proses(double total) {
        double uangDiberikan = 200000; // contoh uang yang diberikan
        double kembalian = uangDiberikan - total;
        System.out.println("=== Pembayaran Tunai ===");
        System.out.println("Total belanja : Rp " + total);
        System.out.println("Uang diberikan: Rp " + uangDiberikan);
        System.out.println("Kembalian     : Rp " + kembalian);
        System.out.println();
    }
}

// Subclass 2: Kartu
class Kartu extends Pembayaran {
    @Override
    public void proses(double total) {
        double biayaAdmin = 2500;
        double totalBayar = total + biayaAdmin;
        System.out.println("=== Pembayaran Kartu ===");
        System.out.println("Total belanja   : Rp " + total);
        System.out.println("Biaya admin     : Rp " + biayaAdmin);
        System.out.println("Total dibebankan: Rp " + totalBayar);
        System.out.println();
    }
}

// Subclass 3: DompetDigital
class DompetDigital extends Pembayaran {
    @Override
    public void proses(double total) {
        double potongan = total * 0.05; // potongan 5%
        double totalBayar = total - potongan;
        System.out.println("=== Pembayaran Dompet Digital ===");
        System.out.println("Total belanja : Rp " + total);
        System.out.println("Potongan 5%   : Rp " + potongan);
        System.out.println("Total bayar   : Rp " + totalBayar);
        System.out.println();
    }
}

// Tester / Main class
public class Main {
    public static void main(String[] args) {
        // Membuat array Pembayaran yang berisi berbagai jenis pembayaran
        Pembayaran[] daftarPembayaran = {
            new Tunai(),
            new Kartu(),
            new DompetDigital()
        };

        double totalBelanja = 150000;

        // Iterasi array dan panggil proses() → menunjukkan efek polymorphism
        for (Pembayaran p : daftarPembayaran) {
            p.proses(totalBelanja);
        }
    }
}
