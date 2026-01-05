// DATA KURSI KERETA JAWA (linked list versi sederhana)
let kursi = [];
for (let i = 1; i <= 12; i++) {
  kursi.push({ no: i, terisi: false });
}

const container = document.getElementById("kursi");

// RENDER KURSI
function render() {
  container.innerHTML = "";
  kursi.forEach((k, i) => {
    let div = document.createElement("div");
    div.className = "seat " + (k.terisi ? "taken" : "free");
    div.innerText = k.no;
    div.onclick = () => pesan(i);
    container.appendChild(div);
  });
}

// PESAN KURSI
function pesan(i) {
  if (kursi[i].terisi) {
    alert("Kursi sudah terisi");
  } else {
    kursi[i].terisi = true;

    // SIMPAN AKSI UNTUK UNDO / REDO
    simpanAksi({
      kursi: kursi,
      index: i,
      render: render
    });

    alert("Kursi berhasil dipesan");
    render();
  }
}

// KEMBALI KE MENU
function kembali() {
  window.location.href = "menu.html";
}

// PERTAMA KALI TAMPIL
render();
