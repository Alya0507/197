let kursi = [
  { no:1, terisi:false },
  { no:2, terisi:false },
  { no:3, terisi:false },
  { no:4, terisi:false },
  { no:5, terisi:false },
  { no:6, terisi:false },
  { no:7, terisi:false },
  { no:8, terisi:false }
];

const container = document.getElementById("kursi");

function render(){
  container.innerHTML="";
  kursi.forEach((k,i)=>{
    let div = document.createElement("div");
    div.className = "seat " + (k.terisi ? "taken":"free");
    div.innerText = k.no;
    div.onclick = ()=> pesan(i);
    container.appendChild(div);
  });
}

function pesan(i){
  if(kursi[i].terisi){
    alert("Kursi sudah terisi");
  }else{
    kursi[i].terisi = true;

    // SIMPAN AKSI KE STACK
    simpanAksi({
      kursi: kursi,
      index: i,
      render: render
    });

    alert("Kursi berhasil dipesan");
    render();
  }
}

function kembali(){
  window.location.href="menu.html";
}

render();
