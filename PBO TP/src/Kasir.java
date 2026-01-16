import java.util.ArrayList;
import java.util.List;

public class Kasir extends User {
    private String idKasir;

    private List<Transaksi> daftarTransaksi = new ArrayList<>();

    public Kasir(String idKasir, String nama, String username, String password) {
        super(nama, username, password);
        this.idKasir = idKasir;
    }

    @Override
    public boolean login(String username, String password) {
        if (super.login(username, password)) {
            System.out.println("Login Kasir Berhasil");
            return true;
        } else {
            System.out.println("Login Gagal");
            return false;
        }
    }

    public void inputTransaksi(Transaksi transaksi) {
        daftarTransaksi.add(transaksi);
        System.out.println("Transaksi dengan ID " + transaksi.getIdTransaksi() + " dicatat.");
    }

    public void cetakStruk(Transaksi transaksi) {
        System.out.println("\n--- STRUK PEMBAYARAN ---");
        System.out.println("Kasir: " + this.getUsername());
        System.out.println("ID Transaksi: " + transaksi.getIdTransaksi());
        System.out.println("Total Bayar: " + transaksi.getTotal());
        System.out.println("Uang Bayar: " + transaksi.getUangBayar());
        System.out.println("Kembalian: " + transaksi.getKembalian());
        System.out.println("------------------------");
    }

    public String getIdKasir() {
        return idKasir;
    }
}