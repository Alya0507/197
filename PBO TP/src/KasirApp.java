import com.formdev.flatlaf.FlatLightLaf;
import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.io.*;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class KasirApp extends JFrame {
    private Kasir kasir;
    private Transaksi transaksi;
    private Barang[] daftarBarang = new Barang[50];

    private JTextField txtUser, txtCari, txtJumlah, txtBayar;
    private JPasswordField txtPass;
    private JComboBox<Barang> cmbBarang;
    private JTextArea areaStruk;
    private JLabel lblTotal, lblStok;
    private JTable table;
    private DefaultTableModel model;

    private final String COKLAT_TUA = "#7F5539";
    private final String COKLAT_SUSU = "#B08968";
    private final String CREAM_BG = "#FDF8F5";
    private final String TEXT_DARK = "#4E342E";

    public KasirApp() {
        kasir = new Kasir("KSR001", "Adalah Pokoknya", "INFORMATIKA", "12345678");
        initBarang();
        loadStokDariFile();

        setTitle("UAD MiniMarket - Informatika Sistem");
        setSize(1000, 800);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        tampilLogin();
    }

    private void initBarang() {
        String[] nama = {
                "Beras 5kg", "Mie Instan", "Minyak Goreng 1L", "Garam Dapur", "Gula Pasir 1kg",
                "Sabun Mandi", "Shampoo", "Pasta Gigi", "Snack Keripik", "Kopi Bubuk",
                "Teh Celup", "Susu UHT 1L", "Telur Ayam 1kg", "Kecap Manis", "Saus Sambal",
                "Tepung Terigu", "Mentega", "Keju Kraft", "Sarden Kaleng", "Kornet Sapi",
                "Sabun Cuci Piring", "Deterjen 800g", "Pelembut Pakaian", "Pembersih Lantai", "Tisu Wajah",
                "Popok Bayi", "Pembalut Wanita", "Obat Nyamuk Semprot", "Sikat Gigi", "Minyak Kayu Putih",
                "Air Mineral 600ml", "Minuman Soda", "Jus Buah Kotak", "Susu Kental Manis", "Biskuit Kaleng",
                "Cokelat Batang", "Permen Bag", "Keripik Kentang", "Kacang Atom", "Roti Tawar",
                "Pulpen Gel", "Buku Tulis", "Penghapus", "Penggaris 30cm", "Baterai AA",
                "Lampu LED 10W", "Selai Kacang", "Madu Murni", "Sirup Cocopandan", "Kapas Kecantikan"
        };

        int[] harga = {
                65000, 3000, 18000, 2500, 14500,
                4500, 15000, 12500, 8000, 10000,
                6000, 19000, 28000, 11000, 9500,
                12000, 8500, 22000, 10500, 25000,
                5000, 23000, 15000, 14000, 7500,
                55000, 18000, 32000, 6000, 16000,
                4000, 7000, 8500, 12000, 35000,
                15000, 8000, 13000, 9000, 15000,
                5000, 6500, 2000, 4000, 12000,
                35000, 28000, 45000, 22000, 9000
        };

        for (int i = 0; i < 50; i++) {
            String id = "B" + String.format("%03d", i + 1);
            daftarBarang[i] = new Barang(id, nama[i], harga[i], 100);
        }
    }

    private void tampilLogin() {
        JPanel panel = new JPanel(new GridBagLayout());
        panel.setBackground(Color.decode(CREAM_BG));
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(10, 10, 10, 10);

        JLabel lblLogo = new JLabel("UAD MINIMARKET");
        lblLogo.setFont(new Font("Segoe UI", Font.BOLD, 28));
        lblLogo.setForeground(Color.decode(COKLAT_TUA));

        txtUser = new JTextField(15);
        txtPass = new JPasswordField(15);
        JButton btnLogin = new JButton("LOGIN");
        styleButton(btnLogin, COKLAT_TUA, Color.WHITE);

        gbc.gridx = 0; gbc.gridy = 0; gbc.gridwidth = 2;
        panel.add(lblLogo, gbc);

        gbc.gridwidth = 1; gbc.gridy = 1;
        panel.add(new JLabel("Username:"), gbc);
        gbc.gridx = 1; panel.add(txtUser, gbc);

        gbc.gridx = 0; gbc.gridy = 2;
        panel.add(new JLabel("Password:"), gbc);
        gbc.gridx = 1; panel.add(txtPass, gbc);

        gbc.gridx = 0; gbc.gridy = 3; gbc.gridwidth = 2;
        panel.add(btnLogin, gbc);

        add(panel);

        btnLogin.addActionListener(e -> {
            if (kasir.login(txtUser.getText(), new String(txtPass.getPassword()))) {
                getContentPane().removeAll();
                tampilKasir();
                revalidate();
                repaint();
            } else {
                JOptionPane.showMessageDialog(this, "Akses Ditolak!", "Error", JOptionPane.ERROR_MESSAGE);
            }
        });
    }

    // ================= VIEW: KASIR UTAMA (Coklat Style) =================
    private void tampilKasir() {
        transaksi = new Transaksi("TRX-" + System.currentTimeMillis());
        getContentPane().setBackground(Color.decode(CREAM_BG));
        setLayout(new BorderLayout(15, 15));

        // --- TOP: INPUT AREA ---
        JPanel pnlInput = new JPanel(new GridBagLayout());
        pnlInput.setBackground(Color.decode(CREAM_BG));
        pnlInput.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createTitledBorder("Transaksi Baru"), new EmptyBorder(10, 15, 10, 15)
        ));
        GridBagConstraints g = new GridBagConstraints();
        g.fill = GridBagConstraints.HORIZONTAL; g.insets = new Insets(5, 8, 5, 8);

        txtCari = new JTextField();
        cmbBarang = new JComboBox<>();
        lblStok = new JLabel("Stok: -");
        lblStok.setForeground(Color.decode(COKLAT_TUA));
        txtJumlah = new JTextField();

        JButton btnCari = new JButton("Cari");
        styleButton(btnCari, COKLAT_SUSU, Color.WHITE);
        JButton btnTambah = new JButton("Tambah ke Keranjang");
        styleButton(btnTambah, COKLAT_TUA, Color.WHITE);

        g.gridx = 0; g.gridy = 0; pnlInput.add(new JLabel("Cari Barang:"), g);
        g.gridx = 1; g.weightx = 1.0; pnlInput.add(txtCari, g);
        g.gridx = 2; g.weightx = 0; pnlInput.add(btnCari, g);

        g.gridx = 0; g.gridy = 1; pnlInput.add(new JLabel("Pilih Item:"), g);
        g.gridx = 1; pnlInput.add(cmbBarang, g);
        g.gridx = 2; pnlInput.add(lblStok, g);

        g.gridx = 0; g.gridy = 2; pnlInput.add(new JLabel("Jumlah:"), g);
        g.gridx = 1; pnlInput.add(txtJumlah, g);
        g.gridx = 2; pnlInput.add(btnTambah, g);

        // --- CENTER: TABLE & ACTIONS ---
        model = new DefaultTableModel(new String[]{"Produk", "Qty", "Harga", "Subtotal"}, 0);
        table = new JTable(model);
        table.setRowHeight(30);
        table.setSelectionBackground(Color.decode("#EDE0D4"));
        JScrollPane scrollTable = new JScrollPane(table);

        JButton btnHapus = new JButton("Hapus Item");
        styleButton(btnHapus, "#E29578", Color.WHITE); // Coklat agak kemerahan (Warning)

        JPanel pnlCenter = new JPanel(new BorderLayout(5, 5));
        pnlCenter.add(scrollTable, BorderLayout.CENTER);
        pnlCenter.add(btnHapus, BorderLayout.SOUTH);

        // --- EAST: STRUK PREVIEW ---
        areaStruk = new JTextArea(20, 32);
        areaStruk.setEditable(false);
        areaStruk.setFont(new Font("Monospaced", Font.PLAIN, 12));
        areaStruk.setBackground(Color.decode("#FAF3E0"));
        areaStruk.setForeground(Color.decode(TEXT_DARK));
        JScrollPane scrollStruk = new JScrollPane(areaStruk);
        scrollStruk.setBorder(BorderFactory.createTitledBorder("Struk Preview"));

        // --- SOUTH: PAYMENT ---
        JPanel pnlSouth = new JPanel(new BorderLayout(10, 10));
        pnlSouth.setBackground(Color.decode(CREAM_BG));
        pnlSouth.setBorder(new EmptyBorder(10, 15, 15, 15));

        lblTotal = new JLabel("TOTAL: Rp 0");
        lblTotal.setFont(new Font("Segoe UI", Font.BOLD, 32));
        lblTotal.setForeground(Color.decode(COKLAT_TUA));

        JPanel pnlBayar = new JPanel(new FlowLayout(FlowLayout.RIGHT));
        pnlBayar.setBackground(Color.decode(CREAM_BG));
        txtBayar = new JTextField(12);
        txtBayar.setFont(new Font("Segoe UI", Font.BOLD, 18));
        JButton btnBayar = new JButton("BAYAR & CETAK");
        styleButton(btnBayar, COKLAT_TUA, Color.WHITE);
        btnBayar.setPreferredSize(new Dimension(220, 45));

        pnlBayar.add(new JLabel("Uang Bayar: Rp"));
        pnlBayar.add(txtBayar);
        pnlBayar.add(btnBayar);

        pnlSouth.add(lblTotal, BorderLayout.WEST);
        pnlSouth.add(pnlBayar, BorderLayout.EAST);

        // Assemble
        add(pnlInput, BorderLayout.NORTH);
        add(pnlCenter, BorderLayout.CENTER);
        add(scrollStruk, BorderLayout.EAST);
        add(pnlSouth, BorderLayout.SOUTH);

        // Events
        tampilkanSemuaBarang();
        btnCari.addActionListener(e -> cariBarang());
        btnTambah.addActionListener(e -> tambahBarang());
        btnHapus.addActionListener(e -> hapusBarang());
        btnBayar.addActionListener(e -> prosesBayar());
    }

    private void styleButton(JButton btn, String hexColor, Color textColor) {
        btn.setBackground(Color.decode(hexColor));
        btn.setForeground(textColor);
        btn.setFont(new Font("Segoe UI", Font.BOLD, 12));
        btn.setCursor(new Cursor(Cursor.HAND_CURSOR));
        btn.setFocusPainted(false);
        btn.setBorder(BorderFactory.createEmptyBorder(10, 15, 10, 15));
    }

    // ================= LOGIC: STOK & TRANSAKSI =================
    private void tambahBarang() {
        try {
            int qty = Integer.parseInt(txtJumlah.getText());
            Barang b = (Barang) cmbBarang.getSelectedItem();

            if (b != null && qty > 0) {
                if (qty <= b.getStok()) {
                    // SATU-SATUNYA TEMPAT PENGURANGAN STOK
                    b.setStok(b.getStok() - qty);

                    // Kirim ke transaksi HANYA untuk mencatat data (bukan kurangi stok lagi)
                    transaksi.tambahBarang(b, qty);

                    // Update Tabel
                    model.addRow(new Object[]{b.getNamaBarang(), qty, b.getHarga(), (b.getHarga() * qty)});

                    // Update UI
                    lblStok.setText("Stok: " + b.getStok());
                    lblTotal.setText("TOTAL: Rp " + transaksi.hitungTotal());

                    txtJumlah.setText("");
                } else {
                    JOptionPane.showMessageDialog(this, "Stok tidak cukup!");
                }
            }
        } catch (Exception e) {
            JOptionPane.showMessageDialog(this, "Input tidak valid!");
        }
    }

    private void hapusBarang() {
        int row = table.getSelectedRow();
        if (row != -1) {
            String nama = model.getValueAt(row, 0).toString();
            int qty = Integer.parseInt(model.getValueAt(row, 1).toString());

            for (Barang b : daftarBarang) {
                if (b != null && b.getNamaBarang().equals(nama)) {
                    b.setStok(b.getStok() + qty); // Stok kembali
                    Barang current = (Barang) cmbBarang.getSelectedItem();
                    if (current != null && current.getNamaBarang().equals(nama)) {
                        lblStok.setText("Stok: " + b.getStok());
                    }
                    break;
                }
            }
            model.removeRow(row);
            lblTotal.setText("TOTAL: Rp " + transaksi.hitungTotal());
            simpanStokKeFile();
        }
    }

    private void prosesBayar() {
        if (model.getRowCount() == 0) return;
        try {
            double bayar = Double.parseDouble(txtBayar.getText());
            if (bayar < transaksi.getTotal()) {
                JOptionPane.showMessageDialog(this, "Uang Kurang!");
                return;
            }
            transaksi.prosesBayar(bayar);
            cetakDanSimpanStruk();

            if (JOptionPane.showConfirmDialog(this, "Berhasil! Transaksi Baru?", "Selesai", 0) == 0) {
                resetTransaksi();
            }
        } catch (Exception e) {
            JOptionPane.showMessageDialog(this, "Cek Nominal Uang!");
        }
    }

    private void cetakDanSimpanStruk() {
        String waktu = LocalDateTime.now().format(DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm"));
        StringBuilder sb = new StringBuilder();
        sb.append("===============================\n");
        sb.append("         UAD MINIMARKET        \n");
        sb.append("-------------------------------\n");
        sb.append("Tgl    : ").append(waktu).append("\n");
        sb.append("Kasir  : ").append(kasir.getNama()).append("\n");
        sb.append("-------------------------------\n");

        for (int i = 0; i < model.getRowCount(); i++) {
            sb.append(String.format("%-15s x%s  Rp%s\n",
                    model.getValueAt(i,0), model.getValueAt(i,1), model.getValueAt(i,3)));
        }

        sb.append("-------------------------------\n");
        sb.append("TOTAL      : Rp ").append(transaksi.getTotal()).append("\n");
        sb.append("BAYAR      : Rp ").append(transaksi.getUangBayar()).append("\n");
        sb.append("KEMBALI    : Rp ").append(transaksi.getKembalian()).append("\n");
        sb.append("===============================\n");

        areaStruk.setText(sb.toString());

        try (BufferedWriter bw = new BufferedWriter(new FileWriter("Struk_" + System.currentTimeMillis() + ".txt"))) {
            bw.write(sb.toString());
        } catch (IOException e) { e.printStackTrace(); }
    }

    private void resetTransaksi() {
        model.setRowCount(0);
        transaksi = new Transaksi("TRX-" + System.currentTimeMillis());
        lblTotal.setText("TOTAL: Rp 0");
        txtBayar.setText("");
        areaStruk.setText("");
    }

    // ================= LOGIC: FILE & DATA =================
    private void simpanStokKeFile() {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter("stok_barang.txt"))) {
            for (Barang b : daftarBarang) {
                if (b != null) bw.write(b.getKodeBarang() + "," + b.getNamaBarang() + "," + b.getHarga() + "," + b.getStok() + "\n");
            }
        } catch (IOException e) { e.printStackTrace(); }
    }

    private void loadStokDariFile() {
        File file = new File("stok_barang.txt");
        if (!file.exists()) {
            System.out.println("File tidak ditemukan, menggunakan data default.");
            return;
        }

        try (BufferedReader br = new BufferedReader(new FileReader(file))) {
            String baris;
            int i = 0;
            while ((baris = br.readLine()) != null && i < 50) {
                String[] data = baris.split(",");
                if (data.length == 4) {
                    String kode = data[0];
                    String nama = data[1];
                    double harga = Double.parseDouble(data[2]);
                    int stok = Integer.parseInt(data[3]);

                    daftarBarang[i] = new Barang(kode, nama, (int)harga, stok);
                    i++;
                }
            }
        } catch (IOException | NumberFormatException e) {
            System.err.println("Error saat membaca file: " + e.getMessage());
        }
    }

    private void tampilkanSemuaBarang() {
        cmbBarang.removeAllItems();
        for (Barang b : daftarBarang) if (b != null) cmbBarang.addItem(b);
        cmbBarang.addActionListener(e -> {
            Barang b = (Barang) cmbBarang.getSelectedItem();
            if (b != null) lblStok.setText("Stok: " + b.getStok());
        });
    }

    private void cariBarang() {
        String key = txtCari.getText().toLowerCase();
        cmbBarang.removeAllItems();
        for (Barang b : daftarBarang) {
            if (b != null && b.getNamaBarang().toLowerCase().contains(key)) cmbBarang.addItem(b);
        }
    }

    public static void main(String[] args) {
        try {
            // Setup Visual Modern
            UIManager.put("Button.arc", 15);
            UIManager.put("Component.arc", 15);
            UIManager.put("TextComponent.arc", 15);
            UIManager.put("Table.rowHeight", 30);
            FlatLightLaf.setup();
        } catch (Exception ex) { ex.printStackTrace(); }
        SwingUtilities.invokeLater(() -> new KasirApp().setVisible(true));
    }
}