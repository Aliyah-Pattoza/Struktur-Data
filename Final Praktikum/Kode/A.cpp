#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct Peserta {
    string IpAddress;
    string NamaPeserta;
};

struct Pesan {
    string pengirim;
    string tujuan;
    string pesantertulis;
};

void DataPeserta(map<string, string>& peserta, int N) {
    for (int i = 0; i < N; i++) {
        Peserta p;
        cin >> p.IpAddress >> p.NamaPeserta;
        peserta[p.IpAddress] = p.NamaPeserta;
    }
}

void DataPesan(map<string, map<string, vector<string>>>& pesan, const map<string, string>& peserta, int Q) {
    for (int i = 0; i < Q; i++) {
        Pesan ps;
        cin >> ps.pengirim >> ps.tujuan;
        getline(cin, ps.pesantertulis);
        if (peserta.find(ps.pengirim) == peserta.end() || peserta.find(ps.tujuan) == peserta.end()) {
            continue;
        }
        pesan[ps.tujuan][ps.pengirim].push_back(ps.pesantertulis);
    }
}

void printPesan(const map<string, map<string, vector<string>>>& pesan, const map<string, string>& peserta) {
    for (const auto& pair : pesan) {
        const string& tujuan = pair.first;
        const auto& pesanTujuan = pair.second;

        if (pesanTujuan.empty())
            continue;

        cout << "===========" << endl;
        cout << "Mail: " << peserta.at(tujuan) << endl;

        for (const auto& pesanAkun : pesanTujuan) {
            const string& pengirim = pesanAkun.first;
            const auto& pesanV= pesanAkun.second;

            cout << "From: " << peserta.at(pengirim) << endl;

            for (const string& pesanT : pesanV) {
                cout << ">> " << pesanT << endl;
            }
        }
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;

    map<string, string> peserta;
    DataPeserta(peserta, N);

    map<string, map<string, vector<string>>> pesan;
    DataPesan(pesan, peserta, Q);

    printPesan(pesan, peserta);

    return 0;
}
