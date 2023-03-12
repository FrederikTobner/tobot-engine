# Generates documentation using doxyxgen (https://www.doxygen.nl/)
if [ -d "../packages/tobot_math/src" ]
then
    echo "Generating Documentation of the math ..."
    cd ../packages/tobot_math/src
    doxygen
    echo "Moving generated content out of the html folder ..."
    if [ -d "../docs/tobot-math" ]
    then
        if [ -d "../docs/tobot-math/html" ]
        then
            cp -avr ../docs/tobot-math/html/* ../docs/tobot-math
            echo "Removing html folder ..."
            rm -rf ../docs/tobot-math/html
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
    echo "Could not find source folder of the tobot-math library"
    cd ../scripts
    exit 70
fi
cd ../scripts