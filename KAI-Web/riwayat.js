let data = JSON.parse(localStorage.getItem("riwayat")) || [];
let tabel = document.getElementById("tabel");

function tampil(){
  data.forEach((d,i)=>{
    let row = tabel.insertRow();
    row.insertCell(0).innerText = i+1;
    row.insertCell(1).innerText = d.nama;
    row.insertCell(2).innerText = d.wilayah;
    row.insertCell(3).innerText = d.kereta;
    row.insertCell(4).innerText = d.jumlah;
    row.insertCell(5).innerText = "Rp " + d.total;
    row.insertCell(6).innerText = d.status;

  });
}

function hapus(){
  if(confirm("Hapus semua riwayat?")){
    localStorage.removeItem("riwayat");
    location.reload();
  }
}

function kembali(){
  window.location.href="menu.html";
}

tampil();
