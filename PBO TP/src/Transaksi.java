import java.util.ArrayList;
import java.util.List;

public class Transaksi {
    private String idTransaksi;
    private List<Barang> daftarBarang = new ArrayList<>();
    private List<Integer> daftarQty = new ArrayList<>();
    private double total;
    private double uangBayar;
    private double kembalian;

    public Transaksi(String idTransaksi) {

        this.idTransaksi = idTransaksi;
    }

    public void tambahBarang(Barang barang, int jumlah) {
        this.daftarBarang.add(barang);
        this.daftarQty.add(jumlah);

    }

    public double hitungTotal() {
        this.total = 0;
        for (int i = 0; i < daftarBarang.size(); i++) {
            this.total += (daftarBarang.get(i).getHarga() * daftarQty.get(i));
        }
        return this.total;
    }

    public void prosesBayar(double uangBayar) {
        this.uangBayar = uangBayar;
        this.total = hitungTotal();
        if (uangBayar >= this.total) {
            this.kembalian = uangBayar - this.total;
        } else {
            this.kembalian = 0;
        }
    }

    public String getIdTransaksi() {
        return idTransaksi;
    }
    public double getTotal() {
        return total;
    }
    public double getUangBayar() {
        return uangBayar;
    }
    public double getKembalian() {
        return kembalian;
    }
}