#include <iostream>
#include <api.h>

int main()
{
    Value* value = JSON::deserialize(
        "{\"users\":[{\"id\":1,\"name\":\"Nikita\",\"surname\":\"Yarosh\",\"year\":3,\"credits\":30,\"address\":{\"city\":\"Pardubice\",\"street\":\"Studentska 199\",\"post code\":53009},\"subjects' list\":[\"IMOSI\",\"IWWW\",\"ICPP\",\"IDAS2\"]},{\"id\":2,\"name\":\"Vlad\",\"surname\":\"Ermolaev\",\"year\":3,\"credits\":30,\"address\":{\"city\":\"Kolin\",\"street\":\"Studentska 199\",\"post code\":53009},\"subjects' list\":[\"IMOSI\",\"IWWW\",\"ICPP\",\"IDAS2\"]},{\"id\":3,\"name\":\"Andrii\",\"surname\":\"Andrusenko\",\"year\":3,\"credits\":30,\"address\":{\"city\":\"Prelouc\",\"street\":\"Studentska 199\",\"post code\":53009},\"subjects' list\":[\"IMOSI\",\"IWWW\",\"ICPP\",\"IDAS2\"]},{\"id\":4,\"name\":\"Dmytro\",\"surname\":\"Hrychanok\",\"year\":3,\"credits\":30,\"address\":{\"city\":\"Pardubice\",\"street\":\"Studentska 199\",\"post code\":53009},\"subjects' list\":[\"IMOSI\",\"IWWW\",\"ICPP\",\"IDAS2\"]}]}");
    cout << JSON::serialize(value) << endl;

    delete value;
}
