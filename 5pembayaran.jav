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


DINAMISSS
import java.util.Scanner;

class Pembayaran {
    public void proses(double total) {
        System.out.println("Memproses pembayaran sebesar: Rp " + total);
    }
}

class Tunai extends Pembayaran {
    @Override
    public void proses(double total) {
        Scanner input = new Scanner(System.in);
        System.out.print("Masukkan uang yang diberikan: Rp ");
        double uangDiberikan = input.nextDouble();
        double kembalian = uangDiberikan - total;
        System.out.println("=== Pembayaran Tunai ===");
        System.out.println("Total belanja : Rp " + total);
        System.out.println("Uang diberikan: Rp " + uangDiberikan);
        System.out.println("Kembalian     : Rp " + kembalian);
        System.out.println();
    }
}

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

class DompetDigital extends Pembayaran {
    @Override
    public void proses(double total) {
        double potongan = total * 0.05; // 5% discount
        double totalBayar = total - potongan;
        System.out.println("=== Pembayaran Dompet Digital ===");
        System.out.println("Total belanja : Rp " + total);
        System.out.println("Potongan 5%   : Rp " + potongan);
        System.out.println("Total bayar   : Rp " + totalBayar);
        System.out.println();
    }
}

public class MainPembayaran {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int pilih;
        double totalBelanja;

        do {
            System.out.println("\n=== MENU PEMBAYARAN ===");
            System.out.println("1. Tunai");
            System.out.println("2. Kartu");
            System.out.println("3. Dompet Digital");
            System.out.println("0. Keluar");
            System.out.print("Pilih metode pembayaran: ");
            pilih = input.nextInt();

            if (pilih == 0) {
                System.out.println("Keluar dari program...");
                break;
            }

            System.out.print("Masukkan total belanja: Rp ");
            totalBelanja = input.nextDouble();

            Pembayaran p = null;

            switch (pilih) {
                case 1:
                    p = new Tunai();
                    break;
                case 2:
                    p = new Kartu();
                    break;
                case 3:
                    p = new DompetDigital();
                    break;
                default:
                    System.out.println("Pilihan tidak valid!");
                    break;
            }

            if (p != null) {
                p.proses(totalBelanja); // overriding + polymorphism
            }

        } while (pilih != 0);

        input.close();
    }
}
