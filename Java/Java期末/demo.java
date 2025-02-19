import java.util.*;
import java.io.*;
public class demo {
    boolean loggedIn =false;

    public void doMainMenu(boolean showMainManu) {
        System.out.println("****************************************\n" +
        "1.Show_a 2.Show_p 3.Show_by_c 4.Search 5.Mod 6.Del 7.Add_cont \n" +
        "8.Add_cat 9.Show_cat 10.Set_field 11.Set_page 12.Set_order 13.Set_sort\n" +
        "14.Show_r 15.Opt 16.Show_acc 17.Add_acc 18.Del_acc 19.Mod_acc 20.Logout 99.Exit\n" +
        "****************************************");

        System.out.println("Error_wrong_command");
        System.out.println("Please_enter_again:");

        System.out.println("[0].Go_back_to_main_menu [99].Exit_system");
}


public void doSearchMenu(boolean showMenu) {

        System.out.print("Search by:\n");
        System.out.print("[1].ID [2].Name [3].Birthday \n");
        System.out.print("[0].Go_back_to_main_menu [99].Exit_system\n");

    //System.out.println("[1].Restart_search [0].Go_back_to_main_menu [99].Exit_system");
    
}

public void doShowPerPage() {
    System.out.println("Choose_show_per_page:");
    System.out.println("[3].3_data_per_page [5].5_data_per_page [10].10_data_per_page");
    System.out.println("[d].default [0].Go_back_to_main_menu [99].Exit_system");
    
    System.out.println("show_defalt_perpage");

    System.out.println("[1].Restart_search [0].Go_back_to_main_menu [99].Exit_system");
}

public void doModify() {

    System.out.println("Input_ID_to_be_modified:");
    System.out.println("Error_no_such_data");

    System.out.println("Search_result:");

    System.out.println("Modify_data_success");
}

public void doDelete() {
    System.out.println("Input_ID_to_be_deleted:");
    
    System.out.println("Error_no_such_data");

    System.out.println("Error_no_such_data");

    System.out.println("Delete_data_success");
}

public void doAddContact() {
    System.out.println("Add_contact_success");
}

public void doAddCatalog() {
        System.out.println("Please_input_new_catalog:");
        System.out.println("Add_catalog_"+ input +"_success");

        System.out.println("Error_catalog_too_long");
        System.out.println("Error_catalog_existed");      
}

public void doShowAllCatalog() {
    System.out.println("[Catalog]");
}

public void doSetViewPerpage() {
    System.out.println("show_defalt_perpage:");
    System.out.println("new_show_defalt_perpage:");
}

public void doSetOrder() {
    System.out.println("show_sort_order:");
    System.out.println("Please_input_new_sort_order:");
    
    System.out.println("Input_error_plaese_input_asc_or_des:");
}

public void doSetSortByField() {
    System.out.println("[1].ID [2].Name [3].Phone [4].Cat [5].Email [6].Bd");
    System.out.println("[0].Go_back_to_main_menu [99].Exit_system");
    
                System.out.println("show_sort_field");
                System.out.println("Sorted_by:ID");

                System.out.println("Sorted_by:Name");
                
                System.out.println("Sorted_by:Phone");
                
                System.out.println("Sorted_by:Cat");
                
                System.out.println("Sorted_by:Email");
                
                System.out.println("Sorted_by:Bd");
                
                System.out.println("Error_wrong_data");
                System.out.println("Please_input_again:");
}

public void doDataOptimize() {
    System.out.println("Please_confirm_data_optimize_y_or_n:");
    
                System.out.println("Data_optimize_success");
                
                System.out.println("Data_optimize_denied");

                System.out.println("Error_wrong_data");
                System.out.println("Please_input_again:");

}

public void searchById() {
    System.out.println("Input_target:");

    System.out.println("Error_wrong_data");
    System.out.println("Please_input_again:");

    System.out.println("Error_no_result");

    System.out.println("Search_result:");
}

public void doLogin() {
    try {
        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new FileReader("account.txt"));
        int attempt = 0;
        while(!loggedIn){
            if(attempt < 3){
                System.out.println("Account:");
                String accountname = sc.nextLine();
                System.out.println("Password:");
                String password = sc.nextLine();
                System.out.println("Verify_string:");
                System.out.println("Input_Verify_string:");
                String Verify_string = sc.nextLine();
            }
            
        }
        
    } catch (Exception e) {
        System.out.println("File open error.");
    }
    
        
        
        System.out.println("Error_wrong_account_password_or_verify_string");
        System.out.println("Login_success");
}

public void doAddAccount() {
    System.out.println("New_account:");
    System.out.println("Too_long_please_try_again:");
    System.out.println("New_password:");
    System.out.println("Too_long_please_try_again:");
}
  
public void doModifyAccount() {
    System.out.println("Modify_account:");
        System.out.println("No_account_please_try_again:");
    System.out.println("New_account:");
        System.out.println("Too_long_please_try_again:");
    System.out.println("New_password:");
        System.out.println("Too_long_please_try_again:");
    System.out.println("Modify_account_success");
}
  
public void doDeleteAccount() {
    System.out.println("Delete_account:");
            System.out.println("No_account_please_try_again:");
    System.out.println("Delete_account_success");
}


public boolean doLogout() {
    System.out.println("Please_confirm_to_logout_y_or_n:");
                System.out.println("Error_input");
                System.out.println("Please_input_again:");
     
}

public String getVerify() {
    System.out.println("verify_string");
}
}
