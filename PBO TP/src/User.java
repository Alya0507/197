public class User {
    private String nama;
    private String username;
    private String password;

    public User(String nama, String username, String password) {
        this.nama = nama;
        this.username = username;
        if (password == null || password.trim().isEmpty()) {
            throw new IllegalArgumentException("Password tidak boleh kosong.");
        }
        this.password = password;
    }

    public boolean login(String username, String password) {
        if (this.username.equals(username) && this.password.equals(password)) {
            return true;
        } else {
            return false;
        }
    }

    public void logout() {
        System.out.println(this.username + " telah logout.");
    }

    public String getNama() {
        return nama;
    }

    public String getUsername() {
        return username;
    }

}