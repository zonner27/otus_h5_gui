#include <vector>
#include "graphic_elements.h"
#include "document.h"

int main()
{
    try
    {
        Document doc;
        std::vector<Command*> history;
        history.push_back(new NewDocumentCommand(&doc));
        history.push_back(new ImportDocumentCommand(&doc, "File.txt"));
        history.push_back(new ExportDocumentCommand(&doc, "File.txt"));

        GraphicElements *circle = new Circle;
        history.push_back(new DrawElements(&doc, circle));
        history.push_back(new RemoveElements(&doc, circle));

        GraphicElements *circle_frame = new CircleWithFrame(circle);
        history.push_back(new DrawElements(&doc, circle_frame));
        history.push_back(new RemoveElements(&doc, circle_frame));

        GraphicElements *square = new Square;
        history.push_back(new DrawElements(&doc, square));
        history.push_back(new RemoveElements(&doc, square));

        for (auto c: history)
        {
            c->execute();
        }

    } catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }


    return 0;
}
