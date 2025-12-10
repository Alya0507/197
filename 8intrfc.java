Main.java statis
public class Main {
    public static void main(String[] args) {
        Kalkulator kalk = new Kalkulator(10, 5);

        System.out.println();
        System.out.println("=== OPERASI KALKULATOR BILANGAN 10 DAN 5 ===");
        System.out.println();
        kalk.jumlah();
        kalk.kurang();
        System.out.println("Hasil Perkalian " + kalk.bil1 + " x " + kalk.bil2 + " = " + kalk.kali());
        System.out.println("Hasil Pembagian " + kalk.bil1 + " / " + kalk.bil2 + " = " + kalk.bagi());
    }
}

Main.java dinamis
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int pilih;

        do {
            System.out.println("\n=== MENU KALKULATOR ===");
            System.out.println("1. Penjumlahan");
            System.out.println("2. Pengurangan");
            System.out.println("3. Perkalian");
            System.out.println("4. Pembagian");
            System.out.println("5. Keluar");
            System.out.print("Pilih menu: ");
            pilih = sc.nextInt();

            if (pilih == 5) {
                System.out.println("Keluar...");
                break;
            }

            System.out.print("Masukkan bil1: ");
            double bil1 = sc.nextDouble();
            System.out.print("Masukkan bil2: ");
            double bil2 = sc.nextDouble();

            Kalkulator kalk = new Kalkulator(bil1, bil2);

            switch (pilih) {
                case 1:
                    System.out.println("Hasil Penjumlahan = " + kalk.jumlah());
                    break;
                case 2:
                    System.out.println("Hasil Pengurangan = " + kalk.kurang());
                    break;
                case 3:
                    System.out.println("Hasil Perkalian " + kalk.bil1 + " x " + kalk.bil2 + " = " + kalk.kali());
                    break;
                case 4:
                    System.out.println("Hasil Pembagian = " + kalk.bagi());
                    break;
                default:
                    System.out.println("Menu tidak valid!");
            }

        } while (true);
    }
}

Operasi.Java
public interface Operasi {
    public double jumlah();
    public double kurang();
    public double bagi();
    public double kali();
}

Kalkulator.java
public class Kalkulator implements Operasi {
    double bil1;
    double bil2;

    public Kalkulator(double bil1, double bil2) {
        this.bil1 = bil1;
        this.bil2 = bil2;
    }

    @Override
    public double jumlah() {
        return bil1 + bil2;

    }

    @Override
    public double kurang() {
        return bil1 - bil2;

    }

    @Override
    public double bagi() {
        return bil1*bil2;
    }

    @Override
    public double kali() {
        if(bil2 == 0){
            System.out.println("Pembagian 0 tidak berlaku");
            return 0;
        }
        return bil1/bil2;
    }
}
