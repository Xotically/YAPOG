#ifndef YAPOG_COLLECTION_MAP_HPP
# define YAPOG_COLLECTION_MAP_HPP

# include <map>

# include "YAPOG/Macros.hpp"

namespace yap
{
  namespace collection
  {
    template <typename K, typename V>
    class Map
    {
      public:

        typedef K KeyType;
        typedef V ValueType;
        typedef std::map<KeyType, ValueType> InnerType;
        typedef typename InnerType::value_type DataType;
        typedef typename InnerType::size_type SizeType;
        typedef typename InnerType::iterator ItType;
        typedef typename InnerType::const_iterator ConstItType;

        Map ();

        Map (const Map<K, V>& copy);
        Map& operator= (const Map<K, V>& copy);

        ItType begin ();
        ConstItType begin () const;
        ItType Begin ();
        ConstItType Begin () const;

        ItType end ();
        ConstItType end () const;
        ItType End ();
        ConstItType End () const;

        void Add (const K& key, const V& value);
        void Add (const Map<K, V>& data);

        V* TryGetValue (const K& key);
        bool Contains (const K& key) const;

        void Remove (const K& key);

        void Clear ();

        bool IsEmpty () const;
        SizeType Count () const;

        V& operator[] (const K& key);
        const V& operator[] (const K& key) const;

      private:

        InnerType data_;
    };
  } // namespace collection
} // namespace yap

# include "YAPOG/Collection/Map.hxx"

#endif // YAPOG_COLLECTION_MAP_HPP
