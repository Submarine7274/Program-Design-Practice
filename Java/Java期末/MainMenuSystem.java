import java.io.*;
import java.util.*;

public class MainMenuSystem {

    private static final String CONFIG_FILE = "myconfig.txt";  // 配置文件
    private static final String ACCOUNT_FILE = "account.txt";  // 帳號文件
    private static final String CATALOG_FILE = "catalog.txt";  // 類別文件
    private static final String DATA_FILE = "data.txt";  // 資料文件
    private static boolean loggedIn = false;  // 登入狀態
    private static Map<String, String> config = new HashMap<>();  // 儲存配置文件中的資料
    private static List<String> data = new ArrayList<>(); // 儲存資料

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 讀取配置文件
        config = readConfigFile();

        while (true) {
            // 如果尚未登入，先讓使用者登入
            if (!loggedIn) {
                boolean loginSuccess = login(scanner);
                if (!loginSuccess) {
                    System.out.println("登入失敗，系統退出。");
                    break;
                }
                loggedIn = true;
            }

            showMainMenu();
            System.out.print("請輸入指令: ");
            String command = scanner.nextLine();

            switch (command) {
                case "20": // Logout
                    logout();
                    loggedIn = false; // 登出後設為未登入
                    break;
                case "99": // Exit
                    System.out.println("系統已退出。");
                    scanner.close();
                    return; // 直接退出系統
                case "1": // Show_all
                    showAllData();
                    break;
                case "14": // Show_raw_data
                    showRawData();
                    break;
                case "8": // Add_Catalog
                    addCatalog(scanner);
                    break;
                case "9": // Show_Catalog
                    showCatalog();
                    break;
                case "7": // Add_job
                    addJob(scanner);
                    break;
                case "4": // Search
                    searchData(scanner);
                    break;
                case "6": // Delete
                    deleteData(scanner);
                    break;
                case "5": // Modify
                    modifyData(scanner);
                    break;
                case "3": // Show_by_catalog
                    showByCatalog(scanner);
                    break;
                case "10": // Set_field
                    setField(scanner);
                    break;
                case "12": // Set_Order
                    setOrder(scanner);
                    break;
                case "13": // Set_Sort
                    setSort(scanner);
                    break;
                case "15": // Data_optimize
                    dataOptimize();
                    break;
                case "2": // Show_per_page
                    showPerPage();
                    break;
                case "11": // Set_Page
                    setPage(scanner);
                    break;
                case "16": // Show_account
                    showAccount();
                    break;
                case "17": // Add_account
                    addAccount(scanner);
                    break;
                case "18": // Delete_account
                    deleteAccount(scanner);
                    break;
                case "19": // Modify_account
                    modifyAccount(scanner);
                    break;
                default:
                    System.out.println("無效指令，請重新輸入！");
            }
        }
    }

    // 登入方法
    private static boolean login(Scanner scanner) {
        System.out.println("請輸入帳號、密碼和驗證碼：");
        System.out.print("帳號: ");
        String username = scanner.nextLine();
        System.out.print("密碼: ");
        String password = scanner.nextLine();
        System.out.print("驗證碼: ");
        String verifyCode = scanner.nextLine();

        // 驗證帳號、密碼和驗證碼
        if (validateLogin(username, password, verifyCode)) {
            System.out.println("Login_Success");
            return true;
        } else {
            System.out.println("Login_Failed，請重新嘗試！");
            return false;
        }
    }

    // 驗證帳號、密碼和驗證碼
    private static boolean validateLogin(String username, String password, String verifyCode) {
        // 讀取帳號密碼檔案
        List<String[]> accounts = readAccountFile();
        boolean validAccount = false;

        for (String[] account : accounts) {
            if (account[0].equals(username) && account[1].equals(password)) {
                validAccount = true;
                break;
            }
        }

        if (!validAccount) {
            return false;
        }

        // 讀取驗證碼配置檔案
        if (config.get("verify_string").equals(verifyCode)) {
            return true;
        } else {
            return false;
        }
    }

    // 讀取帳號文件
    private static List<String[]> readAccountFile() {
        List<String[]> accounts = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(ACCOUNT_FILE))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 2) {
                    accounts.add(parts);
                }
            }
        } catch (IOException e) {
            System.out.println("讀取帳號文件失敗: " + e.getMessage());
        }
        return accounts;
    }

    // 讀取配置文件
    private static Map<String, String> readConfigFile() {
        Map<String, String> config = new HashMap<>();
        try (BufferedReader br = new BufferedReader(new FileReader(CONFIG_FILE))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split("=");
                if (parts.length == 2) {
                    config.put(parts[0].trim(), parts[1].trim());
                }
            }
        } catch (IOException e) {
            System.out.println("讀取配置文件失敗: " + e.getMessage());
        }
        return config;
    }

    // 主選單顯示
    private static void showMainMenu() {
        System.out.println("****************************************");
        System.out.println("[1].Show_all [14].Show_raw_data [8].Add_Catalog [9].Show_Catalog");
        System.out.println("[7].Add_job [4].Search [6].Delete [5].Modify [3].Show_by_catalog");
        System.out.println("[10].Set_field [12].Set_Order [13].Set_Sort [15].Data_optimize");
        System.out.println("[2].Show_per_page [11].Set_Page [16].Show_account [17].Add_account");
        System.out.println("[18].Delete_account [19].Modify_account [20].Logout [99].Exit");
        System.out.println("****************************************");
    }

    // 登出方法
    private static void logout() {
        System.out.println("Logout_Success，已登出系統。");
        System.out.println("請重新登入。");
    }

    // 顯示所有資料
    private static void showAllData() {
        List<String> data = readDataFile();
        System.out.println("顯示所有資料...");
        for (String record : data) {
            System.out.println(record);
        }
    }

    // 顯示原始資料
    private static void showRawData() {
        List<String> data = readRawDataFile();
        System.out.println("顯示原始資料...");
        for (String record : data) {
            System.out.println(record);
        }
    }

    // 讀取資料文件
    private static List<String> readDataFile() {
        List<String> data = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(DATA_FILE))) {
            String line;
            while ((line = br.readLine()) != null) {
                data.add(line);
            }
        } catch (IOException e) {
            System.out.println("讀取資料文件失敗: " + e.getMessage());
        }
        return data;
    }

    // 讀取原始資料文件
    private static List<String> readRawDataFile() {
        List<String> data = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(DATA_FILE))) {
            String line;
            while ((line = br.readLine()) != null) {
                data.add(line);  // 假設原始資料未經排序
            }
        } catch (IOException e) {
            System.out.println("讀取原始資料文件失敗: " + e.getMessage());
        }
        return data;
    }

    // 新增分類
    private static void addCatalog(Scanner scanner) {
        System.out.print("請輸入新分類: ");
        String newCatalog = scanner.nextLine();
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(CATALOG_FILE, true))) {
            writer.write(newCatalog + "\n");
            System.out.println("Add_catalog_" + newCatalog + "_success");
        } catch (IOException e) {
            System.out.println("新增分類失敗: " + e.getMessage());
        }
    }

    // 顯示所有分類
    private static void showCatalog() {
        List<String> catalog = readCatalogFile();
        System.out.println("顯示所有分類...");
        for (String category : catalog) {
            System.out.println(category);
        }
    }

    // 讀取分類文件
    private static List<String> readCatalogFile() {
        List<String> catalog = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(CATALOG_FILE))) {
            String line;
            while ((line = br.readLine()) != null) {
                catalog.add(line);
            }
        } catch (IOException e) {
            System.out.println("讀取分類文件失敗: " + e.getMessage());
        }
        return catalog;
    }

    // 新增資料
    private static void addJob(Scanner scanner) {
        System.out.println("新增資料...");
        System.out.print("請輸入ID: ");
        String id = scanner.nextLine();
        System.out.print("請輸入名稱: ");
        String name = scanner.nextLine();
        System.out.print("請輸入生日: ");
        String birthday = scanner.nextLine();
        System.out.print("請輸入分類: ");
        String category = scanner.nextLine();

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(DATA_FILE, true))) {
            writer.write(id + "," + name + "," + birthday + "," + category + "\n");
            System.out.println("Add_job_success");
        } catch (IOException e) {
            System.out.println("新增資料失敗: " + e.getMessage());
        }
    }

    // 搜尋資料
    private static void searchData(Scanner scanner) {
        System.out.print("請輸入搜尋條件: ");
        String query = scanner.nextLine();
        List<String> data = readDataFile();
        System.out.println("搜尋結果:");
        for (String record : data) {
            if (record.contains(query)) {
                System.out.println(record);
            }
        }
    }

    // 刪除資料
    private static void deleteData(Scanner scanner) {
        System.out.print("Input_ID_to_be_deleted: ");
        String id = scanner.nextLine();
        deleteDataById(id);
    }

    // 刪除資料根據ID
    private static void deleteDataById(String id) {
        List<String> data = readDataFile();
        List<String> newData = new ArrayList<>();
        boolean deleted = false;
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(DATA_FILE))) {
            for (String record : data) {
                if (record.startsWith(id)) {
                    System.out.println("Delete_data_success");
                    deleted = true;
                } else {
                    newData.add(record);
                }
            }
            if (deleted) {
                for (String record : newData) {
                    writer.write(record + "\n");
                }
            } else {
                System.out.println("Error_no_such_data");
            }
        } catch (IOException e) {
            System.out.println("刪除資料失敗: " + e.getMessage());
        }
    }

    // 修改資料
    private static void modifyData(Scanner scanner) {
        System.out.print("Input_ID_to_be_modified: ");
        String id = scanner.nextLine();

        List<String> data = readDataFile();
        boolean modified = false;
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(DATA_FILE))) {
            for (String record : data) {
                if (record.startsWith(id)) {
                    System.out.println("目前資料: " + record);
                    String[] parts = record.split(",");
                    System.out.print("修改名稱 (留空跳過): ");
                    String name = scanner.nextLine();
                    if (!name.isEmpty()) parts[1] = name;

                    System.out.print("修改生日 (留空跳過): ");
                    String birthday = scanner.nextLine();
                    if (!birthday.isEmpty()) parts[2] = birthday;

                    System.out.print("修改分類 (留空跳過): ");
                    String category = scanner.nextLine();
                    if (!category.isEmpty()) parts[3] = category;

                    writer.write(String.join(",", parts) + "\n");
                    modified = true;
                    System.out.println("Modify_data_success");
                } else {
                    writer.write(record + "\n");
                }
            }
            if (!modified) {
                System.out.println("Error_no_such_data");
            }
        } catch (IOException e) {
            System.out.println("修改資料失敗: " + e.getMessage());
        }
    }

    // 以分類顯示資料
    private static void showByCatalog(Scanner scanner) {
        System.out.println("依分類顯示資料...");
        List<String> data = readDataFile();
        for (String record : data) {
            System.out.println(record);
        }
    }

    // 設定欄位顯示
private static void setField(Scanner scanner) {
    System.out.println("設定欄位顯示...");
    System.out.println("顯示欄位：");
    System.out.println("1. ID");
    System.out.println("2. 名稱");
    System.out.println("3. 生日");
    System.out.println("4. 分類");

    System.out.print("請選擇要顯示的欄位（以逗號分隔）：");
    String selectedFields = scanner.nextLine();

    // 儲存設定的欄位，這裡簡單用一個列表來儲存選擇的欄位
    List<String> fieldsToDisplay = Arrays.asList(selectedFields.split(","));
    System.out.println("已設定顯示欄位: " + fieldsToDisplay);
}

// 設定排序
private static void setOrder(Scanner scanner) {
    System.out.println("設定排序方式...");
    System.out.println("1. 升序");
    System.out.println("2. 降序");
    System.out.print("請選擇排序方式：");
    String order = scanner.nextLine();

    if (order.equals("1")) {
        System.out.println("已設定為升序");
    } else if (order.equals("2")) {
        System.out.println("已設定為降序");
    } else {
        System.out.println("無效的選項，請重新選擇");
    }
}

// 設定排序項目
private static void setSort(Scanner scanner) {
    System.out.println("設定排序項目...");
    System.out.println("1. ID");
    System.out.println("2. 名稱");
    System.out.println("3. 生日");
    System.out.println("4. 分類");
    System.out.print("請選擇排序項目：");
    String sortBy = scanner.nextLine();

    System.out.println("已設定排序項目為: " + sortBy);
}

// 優化資料
private static void dataOptimize() {
    System.out.println("資料優化處理...");
    // 這裡可以實作資料的去重、清理空值、格式化等優化操作
    System.out.println("資料已優化！");
}

// 顯示每頁資料
private static void showPerPage() {
    System.out.println("顯示每頁資料數量...");
    // 假設我們將每頁顯示的資料數量存儲在配置文件中
    System.out.println("目前設定的每頁資料數量: " + config.get("per_page"));

    System.out.print("請輸入要顯示的資料數量：");
    String perPage = new Scanner(System.in).nextLine();
    config.put("per_page", perPage);
    System.out.println("已設定每頁顯示資料數量為: " + perPage);
}

// 設定頁數顯示
private static void setPage(Scanner scanner) {
    System.out.println("設定每頁顯示資料數...");
    System.out.print("請輸入每頁顯示的資料數量：");
    String pageCount = scanner.nextLine();

    // 更新配置文件中的頁數設定
    config.put("page_count", pageCount);
    System.out.println("每頁顯示資料數量已設為: " + pageCount);
}

// 顯示所有帳號
private static void showAccount() {
    System.out.println("顯示所有帳號...");
    // 顯示帳號列表
    List<String[]> accounts = readAccountFile();
    for (String[] account : accounts) {
        System.out.println("帳號: " + account[0] + ", 密碼: " + account[1]);
    }
}

// 新增帳號
private static void addAccount(Scanner scanner) {
    System.out.println("新增帳號...");
    System.out.print("請輸入帳號名稱: ");
    String username = scanner.nextLine();
    System.out.print("請輸入密碼: ");
    String password = scanner.nextLine();

    // 新增帳號到帳號文件
    try (BufferedWriter writer = new BufferedWriter(new FileWriter(ACCOUNT_FILE, true))) {
        writer.write(username + "," + password + "\n");
        System.out.println("帳號 " + username + " 新增成功！");
    } catch (IOException e) {
        System.out.println("新增帳號失敗: " + e.getMessage());
    }
}

// 刪除帳號
private static void deleteAccount(Scanner scanner) {
    System.out.println("刪除帳號...");
    System.out.print("請輸入要刪除的帳號名稱: ");
    String username = scanner.nextLine();

    List<String[]> accounts = readAccountFile();
    List<String[]> updatedAccounts = new ArrayList<>();
    boolean accountFound = false;

    for (String[] account : accounts) {
        if (!account[0].equals(username)) {
            updatedAccounts.add(account);
        } else {
            accountFound = true;
        }
    }

    if (accountFound) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(ACCOUNT_FILE))) {
            for (String[] account : updatedAccounts) {
                writer.write(account[0] + "," + account[1] + "\n");
            }
            System.out.println("帳號 " + username + " 刪除成功！");
        } catch (IOException e) {
            System.out.println("刪除帳號失敗: " + e.getMessage());
        }
    } else {
        System.out.println("無此帳號，請檢查輸入的帳號名稱！");
    }
}

// 修改帳號
private static void modifyAccount(Scanner scanner) {
    System.out.println("修改帳號...");
    System.out.print("請輸入要修改的帳號名稱: ");
    String username = scanner.nextLine();

    List<String[]> accounts = readAccountFile();
    boolean accountFound = false;

    for (int i = 0; i < accounts.size(); i++) {
        if (accounts.get(i)[0].equals(username)) {
            System.out.print("請輸入新密碼: ");
            String newPassword = scanner.nextLine();
            accounts.get(i)[1] = newPassword;
            accountFound = true;
            break;
        }
    }

    if (accountFound) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(ACCOUNT_FILE))) {
            for (String[] account : accounts) {
                writer.write(account[0] + "," + account[1] + "\n");
            }
            System.out.println("帳號 " + username + " 的密碼已更新！");
        } catch (IOException e) {
            System.out.println("修改帳號失敗: " + e.getMessage());
        }
    } else {
        System.out.println("無此帳號，請檢查輸入的帳號名稱！");
    }
}

}
