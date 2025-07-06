/**
 * @mainpage Documentation Project Circular Queque
 * 
 * @section Introduction
 * Project ini merupakan projek struktur data 
 * menggunakan struktur data queue dengan pendekatan circular array
 * 
 * @section Operation
 * Project ini memiliki beberapa operasi diantaranya:
 * 1. Insert 
 * 2. Delete
 * 3. Display
 * 
 * @section Cara Penggunaan
 * Berikut beberapa menu yang bisa digunakan:
 * 1.  Endque
 * 2. Deque
 * 3. Display
 * 4. Exit
 * 
 * @author Profile
 *  - Nama : Muhammad Rifal Ardi Mustofa
 *  - NIM : 20240140174
 *  - Kelas : TI/D
 * 
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Ardi@umy.ac.id (c) 2025
 * 
 */
#include <iostream>
using namespace std;
/**
 * @class Queues
 * @brief Class ini untuk operasi lengkap queues
 * 
 */
class Queues
{
    private:
    int FRONT; ///< Variable private FRONT untuk menyimpan posisi depan antrian
    int REAR; ///< Variable private REAR untuk menyimpan posisi belakang antrian
    static const int max = 5; ///< Variable private max untuk menyimpan ukuran maksimum antrian
    int queue_array[5]; ///< Variable private queue_array untuk menyimpan elemen antrian

    public:
    /**
     * @brief Construct a new Queues object
     * Set default queues NULL 
     * with FRONT = -1 and REAR = -1
     */
    Queues()
    {
        FRONT = -1;
        REAR = -1;
    }

    /**
     * @brief Method untuk memasukkan data dalam antrian
     * Data dimasukkan dalam variable queue_array
     */
    void insert()
    {
        int num; ///< Variable num untuk menyimpan data yang akan diinputkan 
        cout << "Enter a number: "; 
        cin >> num;
        cout << endl;

        // 1. Cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1 ) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n"; //1.a
            return; //1.b
        }

        // 2. Cek apakah antrian kosong
        if (FRONT == -1)
        {
            FRONT = 0; // 2.a
            REAR = 0; // 2.b
        }
        else
        {
            // Jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }

    /**
     * @brief Method untuk menghapus data dalam antrian
     * Data yang dihapus diambil dari variable queue_array
     */
    void remove()
    {
        // Cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "\nQueue underflow\n"; 
            return;
        }
        cout << "\nThe element deleted from queue is: " << queue_array[FRONT] << "\n";

        // Cek jika hanya antrian hanya memiliki satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            // Jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;  
        }
    }

    /**
     * @brief Method untuk menampilkan data yang diambil dari variable queue_array
     * Data yang ditampilkan diambil dari variable queue_array
     */
    void display()
    {
       int FRONT_position = FRONT; ///< Variable FRONT_position untuk menandakan posisi elemen ada di awal
       int REAR_position = REAR; ///< Variable REAR_position untuk menandakan posisi elemen ada di akhir

       // Cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue is empty"; 
            return;
        }

        cout << "\nElements in the queue are...\n";


        // Jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position)
        {
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
        else
        {
            // Jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array
            while (FRONT_position <= max -1)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }

            FRONT_position = 0;

            // Iterasi dari awal array hingga REAR
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};

/**
 * @brief Fungsi main digunakan untuk memanggil dan menjalankan semua method yang sudah dibuat 
 * Data diambil dari semua method
 */
int main()
{
    Queues q;
    char ch; ///< Variable ch untuk membuat switch case

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert Operation" << endl;
            cout << "2. Implement delete Operation" << endl;
            cout << "3. Display Values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: (1-4)" << endl;
            cin >> ch;
            cout << endl;

            switch(ch)
            {
                case '1':
                {
                    q.insert();
                    break;
                }
                case '2':
                {
                    q.remove();
                    break;
                }                
                case '3':
                {
                    q.display();
                    break;
                }                
                case '4':
                {
                    return 0;
                }
                default:
                {
                    cout << "Invalid Option!!" << endl;
                    break;
                }
            }

        } 
        catch (exception &e)
            {
                cout << "Check for the values entered" << endl;
            }  
    }
}

