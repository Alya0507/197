let transaksi = JSON.parse(localStorage.getItem("lastTransaksi"));
document.getElementById("total").innerText = "Rp " + transaksi.total;

function bayar(){
  transaksi.status = "Lunas";

  let riwayat = JSON.parse(localStorage.getItem("riwayat"));
  riwayat[riwayat.length-1] = transaksi;
  localStorage.setItem("riwayat", JSON.stringify(riwayat));

  alert("Pembayaran berhasil!");
  window.location.href = "riwayat.html";
}
