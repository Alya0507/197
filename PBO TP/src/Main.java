import com.formdev.flatlaf.FlatLightLaf;
public class Main {
    public static void main(String[] args) {

        try {
            FlatLightLaf.setup();
        } catch (Exception ex) {
            System.err.println("Gagal menginisialisasi Look and Feel");
        }
        java.awt.EventQueue.invokeLater(() -> {
            new KasirApp().setVisible(true);
        });

        Barang sosis = new Barang("B001", "Sosis", 5000.0, 50);

        Kasir andi = new Kasir("KSR001", "Andi Pratama", "andi", "rahasia123");
        System.out.println("--- Proses Login ---");
        andi.login("andi", "rahasia123");
        System.out.println("\n--- Proses Transaksi ---");
        Transaksi t1 = new Transaksi("TRX20251214001");
        t1.tambahBarang(sosis, 3);
        double totalBelanja = t1.hitungTotal();
        System.out.println("Total Belanja: " + totalBelanja);
        t1.prosesBayar(20000.0);
        andi.inputTransaksi(t1);
        andi.cetakStruk(t1);

        System.out.println("Sisa Stok Sosis: " + sosis.getStok());
    }
}