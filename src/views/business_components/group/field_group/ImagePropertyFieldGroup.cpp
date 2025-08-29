#include "ImagePropertyFieldGroup.h"
#include "views/business_components/sub_group/field_sub_group/ImageInfoSubGroupFrame.h"
#include "views/business_components/sub_group/field_sub_group/InstrumentInfoSubGroupFrame.h"
#include "views/business_components/sub_group/field_sub_group/GeographicInfoSubGroupFrame.h"

ImagePropertyFieldGroup::ImagePropertyFieldGroup(QWidget *parent)
    : FieldGroupFrame(parent)
{
    setGroupTitle("ImageProperties");
    createSubGroups();
}

ImagePropertyFieldGroup::~ImagePropertyFieldGroup()
{
    
}

void ImagePropertyFieldGroup::createSubGroups()
{
    // Create image info sub group
    ImageInfoSubGroupFrame *imageInfoSubGroup = new ImageInfoSubGroupFrame(this);
    m_subGroups.append(imageInfoSubGroup);
    
    // Create instrument info sub group
    InstrumentInfoSubGroupFrame *instrumentInfoSubGroup = new InstrumentInfoSubGroupFrame(this);
    m_subGroups.append(instrumentInfoSubGroup);
    
    // Create geographic info sub group
    GeographicInfoSubGroupFrame *geographicInfoSubGroup = new GeographicInfoSubGroupFrame(this);
    m_subGroups.append(geographicInfoSubGroup);
}

QList<QWidget*> ImagePropertyFieldGroup::getElements()
{
    return m_subGroups;
}