#ifndef YAPOG_PARTIAL_LAYOUT_MANAGER_HPP
# define YAPOG_PARTIAL_LAYOUT_MANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/LayoutBox.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"

namespace yap
{

  class YAPOG_LIB PartialLayoutManager
  {
    DISALLOW_COPY(PartialLayoutManager);

  public:    
    PartialLayoutManager (LayoutBox& layout);
    virtual ~PartialLayoutManager ();

    void SetCurrentSel (uint curr);
    void SetEnable (bool state);
    void SetSize (float size);
    void AddItem (IWidget* item);
    uint GetSize () const;
    void Refresh ();
    void Clear ();

  private:       
    uint cursorCurSel_;
    uint itemCount_;
    float size_;

    LayoutBox* layout_;

    collection::Array<IWidget*> stock_;
    collection::Array<IWidget*> itemz_;
    bool isEnable_;
    float widthItem_;
  };
} // namespace yap

#endif /* YAPOG_PARTIAL_LAYOUT_MANAGER_HPP! */
