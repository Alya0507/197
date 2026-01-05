let undoStack = JSON.parse(localStorage.getItem("undoStack")) || [];
let redoStack = JSON.parse(localStorage.getItem("redoStack")) || [];

function save(){
  localStorage.setItem("undoStack", JSON.stringify(undoStack));
  localStorage.setItem("redoStack", JSON.stringify(redoStack));
}

function simpanAksi(aksi){
  undoStack.push(aksi);
  redoStack = [];
  save();
}

function undo(){
  if(undoStack.length === 0){
    alert("Tidak ada aksi untuk undo");
    return;
  }

  let aksi = undoStack.pop();
  aksi.kursi[aksi.index].terisi = false;
  redoStack.push(aksi);
  save();

  alert("Undo berhasil");
}

function redo(){
  if(redoStack.length === 0){
    alert("Tidak ada aksi untuk redo");
    return;
  }

  let aksi = redoStack.pop();
  aksi.kursi[aksi.index].terisi = true;
  undoStack.push(aksi);
  save();

  alert("Redo berhasil");
}
