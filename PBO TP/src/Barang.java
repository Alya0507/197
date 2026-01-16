public class Barang {
    private String kodeBarang;
    private String namaBarang;
    private double harga;
    private int stok;

    public Barang(String kodeBarang, String namaBarang, double harga, int stok) {
        this.kodeBarang = kodeBarang;
        this.namaBarang = namaBarang;

        if (harga < 0 || stok < 0) {
            throw new IllegalArgumentException("Harga dan stok tidak boleh negatif.");
        }
        this.harga = harga;
        this.stok = stok;
    }

    public double getTotal(int jumlah) {

        return this.harga * jumlah;
    }

    public void kurangiStok(int jumlah) {
        if (this.stok >= jumlah) {
            this.stok -= jumlah;
        } else {
            System.out.println("Stok tidak cukup untuk " + this.namaBarang);
        }
    }

    public String getKodeBarang() {

        return kodeBarang;
    }
    public String getNamaBarang() {

        return namaBarang;
    }
    public double getHarga() {

        return harga;
    }
    public int getStok() {

        return stok;
    }

    public void setStok(int stok) {

        this.stok = stok;
    }

    public void setHarga(double harga) {

        if (harga >= 0) this.harga = harga;
    }

    @Override
    public String toString() {
        return kodeBarang + " - " + namaBarang + " (Rp " + harga + ")";
    }

}