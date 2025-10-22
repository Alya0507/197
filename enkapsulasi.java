class Mahasiswa {
    // Atribut dibuat private agar tidak bisa diakses langsung
    private String nama;
    private String nim;
    private double ipk;

    // Setter = untuk mengisi / mengubah data
    public void setNama(String n) {
        nama = n;
    }

    public void setNim(String ni) {
        nim = ni;
    }

    public void setIpk(double i) {
        if (i >= 0.0 && i <= 4.0) { // validasi IPK agar tidak salah input
            ipk = i;
        } else {
            System.out.println("IPK tidak valid! Harus antara 0.0 - 4.0");
        }
    }

    // Getter = untuk mengambil / membaca data
    public String getNama() {
        return nama;
    }

    public String getNim() {
        return nim;
    }

    public double getIpk() {
        return ipk;
    }
}

public class Main {
    public static void main(String[] args) {
        Mahasiswa mhs = new Mahasiswa();

        // Mengisi data melalui setter
        mhs.setNama("Alya");
        mhs.setNim("231001");
        mhs.setIpk(3.85);

        // Menampilkan data melalui getter
        System.out.println("=== Data Mahasiswa ===");
        System.out.println("Nama : " + mhs.getNama());
        System.out.println("NIM  : " + mhs.getNim());
        System.out.println("IPK  : " + mhs.getIpk());
    }
}
