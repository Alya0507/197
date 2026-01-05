let isRegister = false;

function showRegister() {
  document.getElementById("title").innerText = "Registrasi Akun";
  document.querySelector("button").innerText = "DAFTAR";
  document.getElementById("toggle").innerHTML =
    'Sudah punya akun? <span onclick="showLogin()">Login</span>';
  isRegister = true;
}

function showLogin() {
  document.getElementById("title").innerText = "Selamat Datang";
  document.querySelector("button").innerText = "MASUK";
  document.getElementById("toggle").innerHTML =
    'Belum punya akun? <span onclick="showRegister()">Daftar</span>';
  isRegister = false;
}

function login() {
  let user = username.value;
  let pass = password.value;

  if (!user || !pass) {
    alert("Isi semua data!");
    return;
  }

  let akun = JSON.parse(localStorage.getItem(user));

  if (isRegister) {
    if (akun) {
      alert("Username sudah terdaftar!");
    } else {
      localStorage.setItem(user, JSON.stringify({ password: pass }));
      alert("Registrasi berhasil!");
      showLogin();
    }
  } else {
    if (!akun || akun.password !== pass) {
      alert("Login gagal!");
    } else {
      alert("Login berhasil!");
      // redirect ke menu utama
      window.location.href = "menu.html";
    }
  }
}
