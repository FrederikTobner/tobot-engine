# Generates documentation using doxyxgen (https://www.doxygen.nl/)
if [ -d "../tobot_engine/src" ]
then
    echo "Generating Documentation ..."
    cd ../tobot_engine/src
    doxygen
    echo "Moving generated content out of the html folder ..."
    if [ -d "../docs" ]
    then
        if [ -d "../docs/html" ]
        then
            cp -avr ../docs/html/* ../docs
            echo "Removing html folder ..."
            rm -rf ../docs/html
            echo "Sucessfully generated documentation!"
        else
            echo "No html folder inside the docs foulder found"
            cd ../scripts
            exit 70
        fi
    else
        echo "No docs folder generated"
        cd ../scripts
        exit 70
    fi
else
    echo "Could not find source folder"
    cd ../scripts
    exit 70
fi
cd ../scripts