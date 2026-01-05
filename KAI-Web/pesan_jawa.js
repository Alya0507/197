const keretaJawa = [
  { nama:"Argo Bromo", harga:750000 },
  { nama:"Taksaka", harga:450000 },
  { nama:"Malabar", harga:500000 }
];

function pesanJawa(){
  let nama = document.getElementById("nama").value;
  let idx = document.getElementById("kereta").value;
  let jumlah = document.getElementById("jumlah").value;

  if(!nama || idx==="" || !jumlah){
    alert("Lengkapi data!");
    return;
  }

  let k = keretaJawa[idx];
  let total = k.harga * jumlah;

  let riwayat = JSON.parse(localStorage.getItem("riwayat")) || [];
  riwayat.push({
    wilayah:"Jawa",
    nama,
    kereta:k.nama,
    jumlah,
    total
  });
  localStorage.setItem("riwayat", JSON.stringify(riwayat));

  let hasil = document.getElementById("hasil");
  hasil.classList.remove("hidden");
  hasil.innerHTML = `
    <h3>✔ Pemesanan Berhasil</h3>
    Nama: ${nama}<br>
    Kereta: ${k.nama}<br>
    Jumlah: ${jumlah}<br>
    <b>Total: Rp ${total}</b>
  `;
}

function kembali(){
  window.location.href="menu.html";
}
